from typing import List
from heapq import *

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        # 题目要求所有工人同时工作，又要让结束时间最早，故需要令每个工人的结束时间都尽可能地早。因此可以用模拟的方式，始终保存每个工人在继续降低一次山的高度后需要的时间，将它们用小顶堆保存，这样每次就可以快速找到继续降低一次山的高度后的最小时间，然后更新即可
        workTime = []
        for i in workerTimes:
            heappush(workTime, (i, i, 1))
        
        res = 0
        for i in range(mountainHeight):
            t, base, n = heappop(workTime)
            res = max(res, t)
            heappush(workTime, (t+base*(n+1), base, n+1)) # 如果已经移了n次山，还要继续移，时间就需要累加base*(n+1)
        
        return res

if __name__ == "__main__":
    s = Solution()
    mountainHeight = 4
    workerTimes = [2,1,1]
    print(s.minNumberOfSeconds(mountainHeight,workerTimes))
