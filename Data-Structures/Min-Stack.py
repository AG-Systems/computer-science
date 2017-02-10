class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.container = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.container.append(x)
    def pop(self):
        """
        :rtype: void
        """
        if len(self.container) > 0:
            self.container.pop()

    def top(self):
        """
        :rtype: int
        """
        if len(self.container) > 0:
            return self.container[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if len(self.container) > 0:
            x = min(self.container)
            return x
        else:
            return self.container

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
