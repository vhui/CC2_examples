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
            if not node.name.endswith("_"+self.version):
                node.name = (node.name+"_"+ self.version)

    def visit_Decl(self, node):
        if isinstance(node, c_ast.Decl):
            if not node.name.endswith("_" + self.version):
                node.name = (node.name + "_" + self.version)
            if isinstance(node.type, c_ast.TypeDecl):
                if not node.type.declname.endswith("_"+self.version):
                    node.type.declname = (node.type.declname+"_"+ self.version)
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


class FuncDefVisitor(c_ast.NodeVisitor):
    def __init__(self, target):
        self.target = target
        self.container = None

    def visit_FuncDef(self, node):
        if (self.container is None and node.decl.name == self.target):
            self.container = node
        return


def getFunc_AST(filename, funcname):
    # Note that cpp is used. Provide a path to your own cpp or
    # make sure one exists in PATH.
    ast = parse_file(filename, use_cpp=True, cpp_path='gcc',
                     cpp_args=['-E', r'-Iutils/fake_libc_include'])

    v = FuncDefVisitor(funcname)
    v.visit(ast)
    return (v.container, ast)


filename1 = "../../../../CC2_examples/neq/LoopMult5/old.c"
filename2 = "../../../../CC2_examples/neq/LoopMult5/new.c"
#filename1 = "new.c"
#filename2 = "old.c"
#ast = parse_file(filename, use_cpp=True, cpp_path='gcc', cpp_args=['-E', r'-Iutils/fake_libc_include'])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--new', type=str, dest='new', default="new.c", help ="new source file" )
    parser.add_argument('--old', type=str, dest ='old', default="old.c", help="old source file")
    parser.add_argument('--gen_new', type=str, dest='gen_new', default="new.c", help ="new generated" )
    parser.add_argument('--gen_old', type=str, dest ='gen_old', default="old.c", help="old generated")
    parser.add_argument('--client', type=str, dest ='client', default="client", help="client function name")
    #parser.add_argument('--lib', type=str, dest='lib', default="lib", help="lib function name")

    args = parser.parse_args()
    path_old = args.old
    path_new = args.new
    gen_old = args.gen_old
    gen_new = args.gen_new
    clientname = args.client

    client1, fulltree1 = getFunc_AST(path_new, clientname)
    client2, fulltree2 = getFunc_AST(path_old, clientname) #eventually something else
    #check if returns
    if isinstance(client1.body.block_items[-1], c_ast.Return):
        client1.body.block_items[-1] = client1.body.block_items[-1].expr
    #if isinstance(client2.body.block_items[-1], c_ast.Return):
    #    client2.body.block_items[-1] = client2.body.block_items[-1].expr

    client2copy = copy.deepcopy(client2)
    v = IDRenameVisitor("1")
    v.visit(client2copy)

    client1.body.block_items.extend(client2copy.body.block_items)
    client1.decl.type.args.params.extend(client2copy.decl.type.args.params)
    #client2 = client1
    client2.body = client1.body
    client2.decl = client1.decl

    generator = c_generator.CGenerator()
    print(generator.visit(fulltree1))
    print(generator.visit(fulltree2))
    import pdb; pdb.set_trace()

    with open(gen_new, 'w+') as f:
        f.write(generator.visit(fulltree1))
    with open(gen_old, 'w+') as f:
        f.write(generator.visit(fulltree2))

    #import pdb; pdb.set_trace()
    #client1.body.block_items[-1].show()
    #client2.body.block_items[-1].show()

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
