class Hashtable(object):
    def __init__(self):
        self.container = []
    def insert(self,key,val):
        hashval = hash(key)
        size = len(self.container)
        if size < 1:
            size = 1
        self.container.insert((hashval % size),val)
    def tableprint(self):
        print(self.container)
    def lookup(self,key):
        hashval = hash(key)
        size = len(self.container)
        if size < 1:
            size = 1
        return self.container[hashval % size]
table = Hashtable()
table.insert("hi","bye")
print(table.lookup("hi"))
