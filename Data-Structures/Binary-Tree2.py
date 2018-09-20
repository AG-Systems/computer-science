class Node:
    def __init__(self,val):
        self.left = None
        self.right = None
        self.val = val
    
class Tree:
    def __init__(self):
        self.root = None
    def getroot(self):
        return self.root
    def insert(self, val):
        if self.root == None:
            self.root = Node(val)
        else:
            self.insertHelper(val, self.root)
    def insertHelper(self, val, node):
        if val < node.val:
            if node.left != None:
                self.insertHelper(val, node.left)
            else:
                node.left = Node(val)
        else:
            if node.right != None:
                self.insertHelper(val, node.right)
            else:
                node.right = Node(val)
    def find(self, val):
        if self.root != None:
            self.findHelper(val, self.root)
        else:
            return None
    def findHelper(self, val, node):
        if val == node.val:
            return node
        elif val < node.val and node.left != None:
            self.findHelper(val, node.left)
        elif val > node.val and node.right != None:
            self.findHelper(val, node.right)
            
    def deleteTree(self):
        self.root = None 
    def printTree(self):
        if self.root != None:
            self.printTreeHelper(self.root)
        else:
            return None
    def printTreeHelper(self, node):
        if node != None:
            self.printTreeHelper(node.left)
            print(node.val)
            self.printTreeHelper(node.right)
            
tree = Tree()
tree.insert(3)
tree.insert(4)
tree.insert(0)
tree.insert(8)
tree.insert(2)
tree.printTree()
#print (tree.find(3)).val
print( tree.find(3))
print("node: ")
print tree.find(10)
tree.deleteTree()
print("deleted tree: ")
tree.printTree()
