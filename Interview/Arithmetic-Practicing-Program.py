import random
from datetime import datetime 
import collections

storage = []
leaderboard = {}
n = 5
startTime= datetime.now()
for x in range(0,n):
    answer = -1
    num1 = random.randint(0, 9)
    num2 = random.randint(0, 9)
    if (num1,num2) in storage:
        while (num1,num2) in storage:
            num1 = random.randint(0, 9)
            num2 = random.randint(0, 9)
    start=datetime.now()
    while sum([num1,num2]) != answer:
        answer = input(str(num1) + " + " + str(num2) + " = ")
        print(answer)
    end=datetime.now()-start
    #print("Time elpased for this problem(hh:mm:ss.ms) {}".format(end))
    print("Time elpased for this problem: " + str(end.total_seconds()))
    if end.total_seconds() not in leaderboard:
        leaderboard[end.total_seconds()] = (num1,num2)
    else:
        leaderboard[float(end.total_seconds() + 0.01)] = (num1,num2)
    storage.append((num1,num2))
    #print(storage)

timeElapsed=datetime.now()-startTime 

print("Time elpased (hh:mm:ss.ms) {}".format(timeElapsed))
print("--------------------------------------------------")
results = collections.OrderedDict(sorted(leaderboard.items()))
counter = 0
for key, value in results.iteritems():
    if counter > 4:
        break
    print("Problem: ")
    print(str(value[0]) + " + " + str(value[1]))
    print("Took this amount of time: " + str(key) + " secs")
    counter += 1
