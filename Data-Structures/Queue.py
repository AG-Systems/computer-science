class Que(object):
    def __init__(self):
        self.container = []
    def push_back(self,n):
        self.container.append(n)
    def pop_front(self):
        if len(self.container) > 0:
            return self.container.pop(0)
    def size(self):
        return len(self.container)
qq = Que()
qq.push_back(5)
qq.push_back(0)
print(qq.pop_front())
print(qq.pop_front())
