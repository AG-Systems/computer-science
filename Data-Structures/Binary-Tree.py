class BinaryTree():
    def __init__(self,val):
        self.left = None
        self.right = None
        self.val = val
    def getLeftChild(self):
        return self.left
    def getRightChild(self):
        return self.right
    def setNodeValue(self,value):
        self.val = value
    def getNodeValue(self):
        return self.val
    def insertLeft(self,value):
        if self.left == None:
            self.left = BinaryTree(value)
        else:
            tree = BinaryTree(value)
            self.left = tree
            tree.left = self.left
    def insertRight(self,value):
        if self.right == None:
            self.right = BinaryTree(value)
        else:
            tree = BinaryTree(value)
            self.right = tree
            tree.right = self.right
        
def TreeTest():
    btree = BinaryTree("Maud")
    btree.insertLeft("Bob")
    btree.insertRight("Tony")
    btree.insertRight("Steven")
    print(btree.getLeftChild())
    print(btree.getRightChild())

TreeTest()
        
