from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x:(x[0], -x[1]))
        res = len(intervals)
        maxRight = 0
        for l, r in intervals:
            if r <= maxRight:
                res -= 1
            else:
                maxRight = r
        return res

if __name__ == "__main__":
    s = Solution()
    intervals = [[1,4],[3,6],[2,8]]
    print(s.removeCoveredIntervals(intervals))
