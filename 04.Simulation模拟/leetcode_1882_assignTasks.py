from typing import List
from heapq import *

class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        n, m = len(servers), len(tasks)
        available = [] # 空闲中的机器，存储其权重和编号
        for i in range(n):
            heappush(available, (servers[i], i))
        
        nonAvailable = [] # 正在做任务的机器，存储其变空闲的时间和其编号
        res = []
        t = 0
        for i,task in enumerate(tasks):
            t = max(t, i)
            if len(available)==0:
                t = nonAvailable[0][0]
            while len(nonAvailable) and nonAvailable[0][0]<=t:
                _, indx = heappop(nonAvailable)
                heappush(available, (servers[indx], indx))

            _, indx = heappop(available)
            res.append(indx)
            heappush(nonAvailable, (t+task, indx))
        return res

if __name__ == "__main__":
    s = Solution()
    servers = [3,3,2]
    tasks = [1,2,3,2,1,2]
    print(s.assignTasks(servers, tasks))
