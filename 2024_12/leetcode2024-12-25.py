from typing import List
from functools import cache

class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        @cache
        def dfs(r1, c1, r2, c2):
            if r1==r2 and c1==c2:
                return 0
            res = float("inf")
            for i in range(r1, r2):
                res = min(res, dfs(r1, c1, i, c2)+dfs(i+1, c1, r2, c2)+horizontalCut[i])
            for i in range(c1, c2):
                res = min(res, dfs(r1, c1, r2, i)+dfs(r1, i+1, r2, c2)+verticalCut[i])
            return res
        return dfs(0, 0, m-1, n-1)

if __name__ == "__main__":
    s = Solution()
    m,n = 3,2
    horizontalCut,verticalCut = [1,3],[5]
    print(s.minimumCost(m,n,horizontalCut,verticalCut))
