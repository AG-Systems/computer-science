class PrioQq(object):
    def __init__(self):
        self.container = []
    def push_back(self,n,rank):
        self.container.append([n,rank])
    def pop_front(self):
        if len(self.container) > 0:
            return self.container.pop(0)
    def highestrank(self):
        self.maxnum = self.container[1][0]
        counter = 0
        print(self.container)
        new_list = [item[1] for item in self.container]
        while counter < len(new_list):
            if new_list[counter] > self.maxnum:
                maxnum = new_list[counter] 
            counter += 1
        return maxnum   
            
    def size(self):
        return len(self.container)

pqq = PrioQq()
pqq.push_back(1,9)
pqq.push_back(2,2)
pqq.push_back(5,10)
pqq.push_back(3,8)
pqq.push_back(7,15)
pqq.push_back(90,15)
print(pqq.pop_front())
print(pqq.highestrank())
