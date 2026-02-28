from typing import List
from collections import defaultdict
from heapq import *

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        # 一个小顶堆freeRooms维护当前空闲的会议室和它们变成空闲的时间，同时按照会议室的编号从小到大排列，另一个小顶堆usingRooms维护当前正在使用的会议室和它们将要变成空闲的时间，同时按照它们将变成空闲的时间从小到大排列，这样，对于一个会议，为了给它安排一个会议室，就有以下两种情况：
        #   1.在当前会议开始之前，已经有空闲的会议室出现了，这时我们就可以将位于freeRooms堆顶的元素弹出，其对应的会议室编号就是我们为该会议安排的会议室，这样我们就可以保证给它安排的会议室编号最小；
        #   2.在当前会议开始之前，没有任何一个空闲的会议室出现，这时我们就需要看哪一个会议室最先结束会议变成空闲，因此可以取usingRooms中的堆顶元素，其对应的会议室编号就是我们需要给该会议安排的会议室，这样就可以保证一个会议室变成空闲后优先安排给开始时间更早的会议；
        # 需要注意的是，在选定一个会议室后，我们还需要将它加入usingRooms中，但如何确定该会议室在和时间变成空闲？如果是第1种情况，那么可以知道所用的会议室变成空闲的时间一定早于当前会议开始时间，因此该会议的结束时间应保持不变；如果是第2种情况，那么所用会议室变成空闲的时间一定晚于当前会议开始时间，因此该会议的结束时间应向后延长
        # 最后，在使用每一个会议室时统计它的使用次数即可
        meetings.sort()
        freeRooms = [] # 当前空闲的会议室
        for i in range(n):
            heappush(freeRooms, (i, 0)) # 初始化
        usingRooms = [] # 当前使用的会议室
        cnt = defaultdict(int)

        for start, end in meetings:
            while usingRooms and usingRooms[0][0] <= start:
                # 更新所有在当前会议开始之前变成空闲的会议室
                time, indx = heappop(usingRooms)
                heappush(freeRooms, (indx, time))

            length = end-start
            if len(freeRooms) > 0: # 有空闲会议室
                indx, time = heappop(freeRooms)
                heappush(usingRooms, (end, indx))
                cnt[indx] += 1
            else: # 无空闲会议室
                if usingRooms:
                    time, indx = heappop(usingRooms)
                    heappush(usingRooms, (time+length, indx))
                    cnt[indx] += 1
        
        maxTimes, res = 0, 0 # 找出出现次数最大且编号最小的会议室
        for i in range(n):
            if cnt[i] > maxTimes:
                maxTimes = cnt[i]
                res = i
        return res

if __name__ == "__main__":
    s = Solution()
    n = 2
    meetings = [[0,10],[1,5],[2,7],[3,4]]
    print(s.mostBooked(n, meetings))
