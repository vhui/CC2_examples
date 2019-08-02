import argparse
from os import path
import copy
from pycparser import parse_file, c_generator, c_ast, c_parser


""" Name change - wrap function call points:
"""
class FuncInlineCGenerator(c_generator.CGenerator):
    def visit_FuncCall(self, n):
        fref = self._parenthesize_unless_simple(n.name)
        return "__inlineCall" + '(' + fref + '(' + self.visit(n.args) + '))'

TOBESWAPPED =set()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--outer', type=str, dest='outer', default="new.c", help="new source file")
    parser.add_argument('--inner', type=str, dest='inner', default="old.c", help="old source file")
    parser.add_argument('--client-outer', type=str, dest='client_outer', default="client", help=" outer client function name")
    parser.add_argument('--client-inner', type=str, dest='client_inner', default="client",
                        help=" inner client function name")
    parser.add_argument('--lib-outer', type=str, dest='lib_outer', default="lib", help="outer lib function name")
    parser.add_argument('--lib-inner', type=str, dest='lib_inner', default="lib", help="inner lib function name")

    args = parser.parse_args()
    path_inner = args.inner
    path_outer = args.outer

    if path.isfile(path_inner) and path.isfile(path_outer):
        inner_ast = parse_file(path_inner, use_cpp=True,
                             cpp_path='gcc',
                             cpp_args=['-E', r'-Iutils/fake_libc_include'])
        outer_ast = parse_file(path_outer, use_cpp=True,
                             cpp_path='gcc',
                             cpp_args=['-E', r'-Iutils/fake_libc_include'])

        client_funcdef_vis = FuncDefVisitor(args.client_outer)
        client_funcdef_vis.visit(outer_ast)
        client_outer = client_funcdef_vis.extract()
        client_funcdef_vis = FuncDefVisitor(args.client_inner)
        client_funcdef_vis.visit(inner_ast)
        client_inner = client_funcdef_vis.extract()
        lib_funcdef_vis = FuncDefVisitor(args.lib_inner)
        lib_funcdef_vis.visit(inner_ast)
        lib_inner = lib_funcdef_vis.extract()

        #preprocessSource
        compoundizer = MakeCompondVisitor()
        compoundizer.visit(client_outer)
        compoundizer.visit(client_inner)

        #locate all lib_call sites in the outer client
        callsite_finder = FuncCallVisitor(args.lib_outer, client_inner)
        callsite_finder.visit(client_outer)
        callsite_finder.work()
        callsite_finder.add_missing_def(client_outer)

        merged_file = c_ast.FileAST(ext=[lib_inner,client_outer])
        printer = c_generator.CGenerator()
        #print(apply_filter(printer.visit(merged_file), callsite_finder.need_to_init))

        parser = c_parser.CParser()
        ast = parser.parse(apply_filter(printer.visit(merged_file), callsite_finder.need_to_init))
        inline_gen = FuncInlineCGenerator()
        print("extern int __inlineCall(int);\n")
        print(inline_gen.visit(ast))

    else:
        print("Invalid input files")
        exit(1)



class MakeCompondVisitor(c_ast.NodeVisitor):

    def visit_FuncDef(self, node):
        if isinstance(node, c_ast.FuncDef):
            if not isinstance(node.body, c_ast.Compound):
                node.body = c_ast.Compound(block_items=[node.body])
        self.generic_visit(node)

    def visit_If(self, node):
        if isinstance(node, c_ast.If):
            if not isinstance(node.iftrue, c_ast.Compound):
                node.iftrue = c_ast.Compound(block_items=[node.iftrue])
            if node.iffalse is not None and not isinstance(node.iffalse, c_ast.Compound):
                node.iffalse = c_ast.Compound(block_items=[node.iffalse])
        self.generic_visit(node)

    def visit_For(self, node):
        if isinstance(node, c_ast.For):
            if not isinstance(node.stmt, c_ast.Compound):
                node.stmt = c_ast.Compound(block_items=[node.stmt])

    def visit_While(self, node):
        if isinstance(node, c_ast.While):
            if not isinstance(node.stmt, c_ast.Compound):
                node.stmt = c_ast.Compound(block_items=[node.stmt])

    def visit_DoWhile(self, node):
        if isinstance(node, c_ast.DoWhile):
            if not isinstance(node.stmt, c_ast.Compound):
                node.stmt = c_ast.Compound(block_items=[node.stmt])


#find the function defintion for given name
class FuncDefVisitor(c_ast.NodeVisitor):
    def __init__(self, target):
        self.target = target
        self.container = None

    def visit_FuncDef(self, node):
        if (self.container is None and node.decl.name == self.target):
            self.container = node
            return
    def extract(self):
        result = self.container
        self.container = None
        return result

class FuncCallVisitor(c_ast.NodeVisitor):
    def __init__(self, lib_name, source):
        self.parent_child = {}
        self.lib_name = lib_name
        self.inline_pending = []
        self.callsite_count =0
        self.inline_source = source
        self.need_to_init = set()

    def generic_visit(self, node):
        """ Called if no explicit visitor function exists for a
            node. Implements preorder visiting of the node.
        """
        for c in node:
            self.parent_child[c] = node
            self.visit(c)

    def visit_FuncCall(self, node):
        if isinstance(node, c_ast.FuncCall):
            if (node.name.name == self.lib_name):
                #find lib callsite, now determine where to inline
                current_node  = node
                parent_node = self.parent_child.get(node, None)
                while (parent_node is not None):
                    if isinstance(parent_node, c_ast.Compound):
                        self.inline_pending.append((parent_node, current_node, self.callsite_count, node))
                        self.callsite_count +=1;
                        break;
                    elif isinstance(parent_node, c_ast.For) and current_node == parent_node.cond:
                        self.inline_pending.append((parent_node.stmt, -1, self.callsite_count, node))
                    elif isinstance(parent_node, c_ast.While) and current_node == parent_node.cond:
                        self.inline_pending.append((parent_node.stmt, -1, self.callsite_count, node))
                    elif isinstance(parent_node, c_ast.DoWhile) and current_node == parent_node.cond:
                        self.inline_pending.append((parent_node.stmt, -1, self.callsite_count, node))
                    current_node = parent_node
                    parent_node = self.parent_child.get(current_node)
            elif node.args:
                self.visit(node.args)

    def work(self):
        global TOBESWAPPED
        self.need_to_init = set()
        for i in range(len(self.inline_pending)):
            target, location, index, origin =  self.inline_pending[i]
            inlining_source = copy.deepcopy(self.inline_source)
            renamer = VaraibleRenameVisitor(i)
            renamer.visit(inlining_source)
            inline_ready_block, replace_variable = remove_inputs(inlining_source, origin.args.exprs, index)
            if (location != -1):
                if isinstance(target, c_ast.Compound):
                    location_index = target.block_items.index(location)
                    origin.name = replace_variable
                    origin.args=None
                    target.block_items = target.block_items[:location_index] + inline_ready_block + target.block_items[location_index:]
                    self.need_to_init.add(replace_variable.name)
            else:
                target.block_items += inline_ready_block

    def add_missing_def(self, node):
        if isinstance(node, c_ast.FuncDef):
            for name in self.need_to_init:
                node.body.block_items.insert(0, c_ast.Decl(name=name, quals=[], storage=[], init=None, funcspec=[],
                           bitsize=None,
                           type=c_ast.TypeDecl(declname=name, quals=[],
                                               type=c_ast.IdentifierType(['int']))))

def remove_inputs(source, args, index):
    if len(args) == 0:
        args = [c_ast.Constant(type='int', value=0)]
    if isinstance(source, c_ast.FuncDef):
        if source.decl.type.args is not None:
            arg_decls = source.decl.type.args.params
            for i in range(len(arg_decls)):
                arg_decl = copy.deepcopy(arg_decls[i])
                arg_decl.init = args[min(i, len(args)-1)]
                source.body.block_items.insert(0, arg_decl)

        ret_hunter = returnHunter(index)
        ret_hunter.visit(source.body)
        ret_hunter.work()

        return source.body.block_items, ret_hunter.tobeinit

class returnHunter(c_ast.NodeVisitor):
    def __init__(self, index):
        self.index = index
        self.toBeReplace ={}
        self.parent_child = {}
        self.tobeinit = None

    def generic_visit(self, node):
        """ Called if no explicit visitor function exists for a
            node. Implements preorder visiting of the node.
        """
        for c in node:
            self.parent_child[c] = node
            self.visit(c)

    def visit_Return(self, node):
        if isinstance(node, c_ast.Return):
            lvalue = c_ast.ID(name="INLINED_RET_{d}".format(d=self.index))
            return_assign = c_ast.Assignment(op='=',lvalue=lvalue, rvalue= node.expr)
            parent = self.parent_child.get(node, None)
            if parent is not None:
                self.toBeReplace[node] = (parent, return_assign)
                self.tobeinit = copy.deepcopy(lvalue)

    def work(self):
        for key, value in self.toBeReplace.items():
            parent, child = value
            if isinstance(parent, c_ast.Compound):
                parent_items = parent.block_items
                location_index = parent_items.index(key)
                parent_items[location_index] = child


class VaraibleRenameVisitor(c_ast.NodeVisitor):
    def __init__(self, index):
        self.index = index

    def visit_FuncCall(self, node):
        if isinstance(node, c_ast.FuncCall):
            if node.args:
                self.visit(node.args)

    def visit_Decl(self, node):
        if isinstance(node, c_ast.Decl):
            suffix = "_copy{d}".format(d=self.index)
            if not node.name.endswith(suffix):
                node.name += suffix
            c_ast.NodeVisitor.generic_visit(self, node)

    def visit_TypeDecl(self, node):
        if isinstance(node, c_ast.TypeDecl):
            suffix = "_copy{d}".format(d=self.index)
            if not node.declname.endswith(suffix):
                node.declname += suffix

    def visit_ID(self, node):
        if isinstance(node, c_ast.ID):
            suffix = "_copy{d}".format(d=self.index)
            if not node.name.endswith(suffix):
               node.name += suffix


def apply_filter(content, filter_set):
    for name in filter_set:
        content = content.replace(name+"()", name)
    return content

if __name__ == "__main__":
    main()
