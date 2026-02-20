from typing import List

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(key = lambda x:x[1])
        maxDay = events[-1][1]
        pa = list(range(maxDay+2)) # 防止超出限制
        def find(x):
            if pa[x] != x:
                pa[x] = find(pa[x])
            return pa[x]
        res = 0
        for start, end in events:
            x = find(start) # 找到start之后的第一个空闲日期
            if x <= end:
                res += 1 # 参加会议，累加答案
                pa[x] = x+1 #连接第x天和第x+1天
        return res
        
        # events.sort(key = lambda x:x[0])
        # n = len(events)
        # maxDay = 0 # 找出最大可能日期
        # for e in events:
        #     maxDay = max(maxDay, e[1])
        
        # res = 0
        # j = 0
        # q = []
        # for i in range(1, maxDay+1):
        #     while j<n and events[j][0]<=i:
		# 		# 加入所有已经开始的会议
        #         heappush(q, events[j][1])
        #         j += 1
        #     while q and q[0]<i:
		# 		# 弹出所有已经结束的会议
        #         heappop(q)
        #     if q:
		# 		# 贪心地参加最近要结束的会议
        #         heappop(q)
        #         res += 1
        # return res

if __name__ == "__main__":
    s = Solution()
    events = [[1,2],[2,3],[3,4]]
    print(s.maxEvents(events))
