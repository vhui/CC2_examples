import sys

from pycparser import c_parser, c_ast, parse_file, c_generator
import copy
import argparse

'''
Rename variables with version
'''
class IDRenameVisitor(c_ast.NodeVisitor):
    def __init__(self, version):
        self.version = version

    def visit_ID(self, node):
        if isinstance(node, c_ast.ID):
            if not node.name.endswith("_copy"+self.version):
                node.name = (node.name+"_copy"+ self.version)

    def visit_Decl(self, node):
        if isinstance(node, c_ast.Decl):
            if not node.name.endswith("_copy" + self.version):
                node.name = (node.name + "_copy" + self.version)
            if isinstance(node.type, c_ast.TypeDecl):
                if not node.type.declname.endswith("_copy"+self.version):
                    node.type.declname = (node.type.declname+"_copy"+ self.version)
            c_ast.NodeVisitor.generic_visit(self, node)
            """if node.init is not None:
                hunter = IDhunterRaw()
                hunter.visit(node.init)
                for tnode in hunter.container:
                    if not tnode.name.endswith("_#" + self.version):
                        self.renamed.add((tnode.name, self.version))
                        tnode.name = (tnode.name+"_#"+ self.version)"""
    def visit_FuncCall(self, node): #avoids renaming calling library
        if node.args:
            self.visit(node.args)

class FuncCallFindVisitor(c_ast.NodeVisitor):
    def __init__(self, name):
        self.name = name
        self.argslist = []
        self.containerlist = []

    def visit_FuncCall(self, node): #avoids renaming calling library
        if (node.name.name == self.name): #node.name AND node.args
            self.containerlist.append( node )
            self.argslist.append( copy.deepcopy(node.args.exprs) )
        c_ast.NodeVisitor.generic_visit(self, node)


class FuncDefVisitor(c_ast.NodeVisitor):
    def __init__(self, target):
        self.target = target
        self.container = None

    def visit_FuncDef(self, node):
        if (self.container is None and node.decl.name == self.target):
            self.container = node
        return


def getFunc_AST(filename, clientname, libname=None):
    # Note that cpp is used. Provide a path to your own cpp or
    # make sure one exists in PATH.
    ast = parse_file(filename, use_cpp=True, cpp_path='gcc',
                     cpp_args=['-E', r'-Iutils/fake_libc_include'])

    clientv = FuncDefVisitor(clientname)
    clientv.visit(ast)

    if libname:
        libv = FuncDefVisitor(libname)
        libv.visit(ast)
        lib_ast = libv.container
        #lib_ast == None, when not found
    return (clientv.container, lib_ast, ast)


filename1 = "../../../../CC2_examples/neq/LoopMult5/old.c"
filename2 = "../../../../CC2_examples/neq/LoopMult5/new.c"
#filename1 = "new.c"
#filename2 = "old.c"
#ast = parse_file(filename, use_cpp=True, cpp_path='gcc', cpp_args=['-E', r'-Iutils/fake_libc_include'])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--new', type=str, dest='new', default="new.c", help ="new source file", required=True)
    parser.add_argument('--old', type=str, dest ='old', default="old.c", help="old source file", required=True)
    parser.add_argument('--new2', type=str, dest='new2', default="new.c", help ="new source file", required=True)
    parser.add_argument('--old2', type=str, dest ='old2', default="old.c", help="old source file", required=True)
    parser.add_argument('--gen_new', type=str, dest='gen_new', default="new.c", help ="new generated" )
    parser.add_argument('--gen_old', type=str, dest ='gen_old', default="old.c", help="old generated")
    parser.add_argument('--client', type=str, dest ='client', default="client", help="client function name")
    parser.add_argument('--lib', type=str, dest='lib', default="lib", help="lib function name")
    parser.add_argument('--client2', type=str, dest ='client2', default="client", help="client2 function name")
    parser.add_argument('--lib2', type=str, dest='lib2', default="lib", help="lib2 function name")
    parser.add_argument('--useV2', action='store_true', default=False) #NOTE use V2 LIBRARIES, PASTE is still 1 before 2


    args = parser.parse_args()
    path_old = args.old
    path_new = args.new
    path_old2 = args.old2
    path_new2 = args.new2
    gen_old = args.gen_old
    gen_new = args.gen_new
    clientname = args.client
    libname = args.lib
    clientname2 = args.client2
    libname2 = args.lib2
    useV2 = args.useV2
    
    if not useV2:
        client1n, lib1n, fulltree1n = getFunc_AST(path_new, clientname, libname)
        client1o, lib1o, fulltree1o = getFunc_AST(path_old, clientname, libname)
        client2n, _2, fulltree2n = getFunc_AST(path_new2, clientname2, libname2) #eventually something else
        _1, _2, fulltree2o = getFunc_AST(path_old2, clientname2, libname2)
        client_box = client1n
        client_in = client2n
    else:
        client2n, _2, fulltree2n = getFunc_AST(path_new, clientname, libname)
        _1, _2, fulltree2o = getFunc_AST(path_old, clientname, libname)
        client1n, lib1n, fulltree1n = getFunc_AST(path_new2, clientname2, libname2) #eventually something else
        client1o, lib1o, fulltree1o = getFunc_AST(path_old2, clientname2, libname2)
        client_box = client1n
        client_in = client2n        
        """client_box = client2n #WRONG!
        client_in = client1n"""
        temp = libname
        libname = libname2
        libname2 = temp
        #temp = clientname
        #clientname = clientname2
        #clientname2 = temp
    #check if returns
    
    boxCallVisitor = FuncCallFindVisitor(libname)
    boxCallVisitor.visit(client_box)
    assert(boxCallVisitor.containerlist[0] is not None)
    args_box = boxCallVisitor.argslist[0]
    boxCallName = boxCallVisitor.containerlist[0].name.name

    inCallVisitor = FuncCallFindVisitor(libname2)
    inCallVisitor.visit(client_in)
    assert(inCallVisitor.containerlist[0] is not None)
    args_in_list = inCallVisitor.argslist
    inFuncCall_list = inCallVisitor.containerlist
    
    for args_in, inFuncCall in zip(args_in_list, inFuncCall_list):
        # TODO always replace client_in(lib_in) with client_in(lib_box), adjusting args to context
        if len(args_box) > 2 or len(args_in) > 2 or len(args_box) <= 0 or len(args_in) <= 0:
            print("Error: Lib call has > 2, or <= 0 args, more preprocessing needed")
            return
        inFuncCall.name.name = boxCallName
        if len(args_box) == 1:
            inFuncCall.args.exprs = inFuncCall.args.exprs[:1]
        elif len(args_box) == 2 and len(args_in) == 2:
            None
        elif len(args_box) == 2 and len(args_in) == 1:
            inFuncCall.args.exprs.extend(args_in)    
    
    if not useV2:
        client1n_RetExpr = None
        if isinstance(client1n.body.block_items[-1], c_ast.Return):
            client1n_RetExpr = copy.deepcopy(client1n.body.block_items[-1].expr)
            client1n.body.block_items[-1] = client1n.body.block_items[-1].expr

        client2ncopy = copy.deepcopy(client2n)
        v = IDRenameVisitor("1")
        v.visit(client2ncopy)
        
        client2n_RetExpr = None
        #TODO: Better INTERACTION between return values of merged benchmarks? (SUM right now)
        if client1n_RetExpr and isinstance(client2ncopy.body.block_items[-1], c_ast.Return):
            client2n_RetExpr = copy.deepcopy(client2ncopy.body.block_items[-1].expr)
            client2ncopy.body.block_items[-1].expr = c_ast.BinaryOp(op='+',left= client1n_RetExpr, right=client2n_RetExpr )
        
        client1n.body.block_items.extend(client2ncopy.body.block_items)
        client1n.decl.type.args.params.extend(client2ncopy.decl.type.args.params)
    else:
        client2n_RetExpr = None
        if isinstance(client2n.body.block_items[-1], c_ast.Return):
            client2n_RetExpr = copy.deepcopy(client2n.body.block_items[-1].expr)
            client2n.body.block_items[-1] = client2n.body.block_items[-1].expr

        client1ncopy = copy.deepcopy(client1n)
        v = IDRenameVisitor("1")
        v.visit(client1ncopy)

        client1n_RetExpr = None
        #TODO: Better INTERACTION between return values of merged benchmarks? (SUM right now)
        if client2n_RetExpr and isinstance(client1ncopy.body.block_items[-1], c_ast.Return):
            client1n_RetExpr = copy.deepcopy(client1ncopy.body.block_items[-1].expr)
            client1ncopy.body.block_items[-1].expr = c_ast.BinaryOp(op='+',left= client2n_RetExpr, right=client1n_RetExpr )
        
        client2n.body.block_items.extend(client1ncopy.body.block_items)
        client2n.decl.type.args.params.extend(client1ncopy.decl.type.args.params)
        client1n.body = client2n.body
        client1n.decl = client2n.decl
    #client1o = client1n
    
    client1o.body = client1n.body
    client1o.decl = client1n.decl

    generator = c_generator.CGenerator()
    print(generator.visit(fulltree1n))
    print(generator.visit(fulltree1o))
    #import pdb; pdb.set_trace()

    with open(gen_new, 'w+') as f:
        f.write(generator.visit(fulltree1n))
    with open(gen_old, 'w+') as f:
        f.write(generator.visit(fulltree1o))

    #import pdb; pdb.set_trace()
    #client1n.body.block_items[-1].show()
    #client1o.body.block_items[-1].show()

# OK, we've seen that the top node is FileAST. This is always the
# top node of the AST. Its children are "external declarations",
# and are stored in a list called ext[] (see _c_ast.cfg for the
# names and types of Nodes and their children).
# As you see from the printout, our AST has two Typedef children
# and one FuncDef child.
# Let's explore FuncDef more closely. As I've mentioned, the list
# ext[] holds the children of FileAST. Since the function
# definition is the third child, it's ext[2]. Uncomment the
# following line to show it:

#ast.ext[2].show()

# A FuncDef consists of a declaration, a list of parameter
# declarations (for K&R style function definitions), and a body.
# First, let's examine the declaration.

#function_decl = ast.ext[2].decl

if __name__ == "__main__":
    main()
