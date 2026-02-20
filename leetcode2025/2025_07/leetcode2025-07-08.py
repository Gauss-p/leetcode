from typing import List
from bisect import *

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        # 动态规划，定义dp[i][j]表示在前i个会议中最多参加j个会议的最大会议价值之和(注意是最多)，那么对于一个dp[i][j]，它有两种组成方式，一种是参加第i个会议，一种是不参加第i个会议。答案即为dp[n][k]，其中n=len(events)
        # 如果是后者，因为如果不包括第i个会议的价值，在前i个会议中最多参加j个会议的最大价值和，就可以直接看作在前i-1个会议中最多参加j个会议的最大价值和，因此那么dp[i][j]就可以直接由上一个值转移过来，即dp[i][j] = dp[i-1][j]；
        # 如果是前者，那么为了参加第i个会议，我们必须找到在第i个会议开始之前就已经结束的最后一个会议，其中“最后一个会议”是为了保证最大值，因为参加越多会议就越能达到更高的价值和。那么这就启示我们可以利用二分查找在排序后的会议结束时间中寻找最后一个结束时间小于第i个会议开始时间的会议，因此，我们可以将“第i个会议”定义为在按照会议结束时间排序后的events中索引为i-1的会议。回到递推关系式，我们就可以先求出最后一个结束时间小于第i个会议开始时间的会议的索引indx，然后，注意dp中和events中的索引是相差1的，因此转移时需要将indx+1，即dp[i][j] = dp[indx+1][j-1]+val，其中val就是第i个会议的价值
        # 因此，对于dp[i][j]，它的递推关系式就应该是dp[i][j] = max(dp[i-1][j], dp[indx][j-1]+val)
        # 在实现代码的时候，我们可以先将events按照索引为1的元素排序，然后为了方便用二分查找函数计算indx的值，我们可以将所有会议的结束时间单独取出来并排序，由于该列表和events列表的排序键是一样的，因此直接在该列表中二分查找即可找到events中的索引indx
        endTime = [] # 取出所有会议的结束时间，方便二分
        for e in events:
            endTime.append(e[1])
        endTime.sort()
        events.sort(key = lambda x:x[1]) # 按照结束时间排序所有会议，即可与endTime列表中的索引对应
        n = len(events)
        dp = [[0]*(k+1) for _ in range(n+1)] # 定义dp[i][j]表示在前i个会议中最多参加j个会议的最大会议价值之和
        for i in range(1, n+1):
            start, end, val = events[i-1]
            indx = bisect_left(endTime, start)-1 # 取出最后一个结束时间小于start的会议的索引
            for j in range(k+1):
                dp[i][j] = dp[i-1][j] # 不参加第i个会议
                if j > 0 and indx+1 < i:
                    # 参加第i个会议，需要注意查出的上一个会议不能在当前会议之后，并且当前需要最多参加的会议数量需要至少为1
                    dp[i][j] = max(dp[i][j], dp[indx+1][j-1]+val) # 注意索引为indx的会议在dp中是第indx+1个会议
        return dp[n][k]

if __name__ == "__main__":
    s = Solution()
    events = [[1,2,4],[3,4,3],[2,3,1]]
    k = 2
    print(s.maxValue(events, k))
