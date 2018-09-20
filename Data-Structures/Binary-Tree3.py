class Node:
  left = None
  right = None
  data = None
  def __init__(self, val=None):
    self.data = val
  def insert(self, value):
    if value <= self.data:
      if self.left == None:
        self.left = Node(value)
      else:
        self.left.insert(value)
    else:
      if self.right == None:
        self.right = Node(value)
      else:
        self.right.insert(value)
  
  def contains(self, value):
    if value == self.data:
      return True
    elif value < self.data:
      if self.left == None:
        return False
      else:
        self.left.contains(value)
    else:
      if self.right == None:
        return False
      else:
        self.right.contains(value)
  
  def printInOrder(self):
    if self.left != None:
      self.left.printInOrder()
    print(self.data)
    if self.right != None:
      self.right.printInOrder()
    
  def printPostOrder(self):
    if self.left != None:
      self.left.printPostOrder()
    if self.right != None:
      self.right.printPostOrder()
    print(self.data)
  
  def printPreOrder(self):
    print(self.data)
    if self.left != None:
      self.left.printPreOrder()
    if self.right != None:
      self.right.printPreOrder()
    

test = Node(10)
test.insert(5)
test.insert(12)
test.insert(1)
print(test.contains(5))


print("In order: ")
test.printInOrder()
print("Post Order: ")
test.printPostOrder()
print("Pre Order: ")
test.printPreOrder()


