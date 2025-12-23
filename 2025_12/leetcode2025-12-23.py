from typing import List
from bisect import *

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # 贪心，对于每一个活动，如果它是作为第二个活动被选择，那么上一个活动的结束时间一定是小于当前活动的开始时间的，因此可以将所有活动按照结束时间顺序排列，二分查找求出最后一个可能的位置，用前缀最大值求解即可
        n = len(events)
        events.sort(key = lambda x:x[1])
        endTime = [x[1] for x in events]
        preMax = [0]*(n+1)
        for i in range(n):
            preMax[i+1] = max(preMax[i], events[i][2])
        
        res = preMax[-1]
        for i in range(n):
            end = events[i][0]-1
            indx = bisect_left(endTime, end+1)-1
            res = max(res, events[i][2]+preMax[indx+1])
        return res

if __name__ == "__main__":
    s = Solution()
    events = [[1,3,2],[4,5,2],[2,4,3]]
    print(s.maxTwoEvents(events))
