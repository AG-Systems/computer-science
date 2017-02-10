class Node(object):
    def __init__(self, n):
        self.val = n
        self.left = None
        self.right = None
def insert(root, node):
    if not root:
        root = node
    else:
        if root.val > node.val:
            if not root.left:
                root.left = node
            else:
                insert(root.left, node)
        else:
            if not root.right:
                root.right = node
            else:
                insert(root.right,node)
def in_order_print(root):
    if not root:
        return
    in_order_print(root.left)
    print root.val
    in_order_print(root.right)    
r = Node(3)
insert(r, Node(7))
insert(r, Node(1))
insert(r, Node(5))    
print "in order:"
in_order_print(r)
