from typing import List
from bisect import *
from functools import cache

class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        # 为了保证题目中的“不重叠”要求，首先要对intervals进行排序，这里根据需求不同需要根据两个不同的关键字进行排序：
        #   1.如果要在知道上一个区间的右端点的情况下，通过二分查找找到下一个最近可能区间的位置，则需要按照左端点增序排序，这个排序方式适用于dfs算法，从左到右不断选择区间；
        #   2.如果要在知道下一个区间的左端点的情况下，通过二分查找找到上一个最近可能区间的位置，则需要按照右端点增序排序，这个排序方式适用于dp算法，根据左侧计算出来的数据转移到当前位置；

        # 用dfs的方式计算，定义dfs函数，其中dfs(i,cnt)表示当前待选区间是在排序后区间中的第i个，且已经选择了cnt个区间时所能得到的最大得分以及其所对应的字典序最小的索引数组，那么当下就有两种情况：
        #   1.不选当前区间，那么答案就变成了dfs(i+1, cnt)
        #   2.选择当前区间，那么下一个可选区间最小也只能是最近的下一个满足其左端点大于当前区间右端点的那个区间j，故答案就变成了dfs(j, cnt+1)，注意需要加上当前区间的信息，即在索引数组中加上i并在得分中加上当前区间权重
        # 最后选择最大得分对应的字典序最小的下标数组即可。
        n = len(intervals)
        pos = sorted(range(n), key = lambda x:intervals[x])
        intervals.sort()
        nxtPos = [bisect_right(intervals, intervals[i][1], key = lambda x:x[0]) for i in range(n)]
        @cache
        def dfs(i, cnt):
            if cnt == 4 or i == n:
                return [], 0
            ans = []
            score = 0
            ans, score = dfs(i+1, cnt)
            
            nxtAns, nxtScore = dfs(nxtPos[i], cnt+1)
            nxtAns = sorted([pos[i]]+nxtAns)
            nxtScore += intervals[i][2]
            if nxtScore > score:
                score = nxtScore
                ans = nxtAns
            elif nxtScore == score and nxtAns < ans:
                ans = nxtAns
            return ans, score
        return dfs(0, 0)[0]
        
        res, sc = dfs(-1, 0)
        return res

if __name__ == "__main__":
    s = Solution()
    intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]
    print(s.maximumWeight(intervals))
