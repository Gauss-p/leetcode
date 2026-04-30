from typing import List
from functools import *

class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        @cache
        def dfs(x, y, cost):
            if cost > k:
                return -10**18
            if x == m-1 and y == n-1:
                return -10**18 if cost+(grid[x][y]>0) > k else grid[x][y]
            ans = -10**18
            if x+1 < m:
                ans = max(ans, grid[x][y]+dfs(x+1, y, cost+(grid[x][y]>0)))
            if y+1 < n:
                ans = max(ans, grid[x][y]+dfs(x, y+1, cost+(grid[x][y]>0)))
            return ans
        res = dfs(0, 0, 0)
        dfs.cache_clear()
        return -1 if res<0 else res

if __name__ == "__main__":
    s = Solution()
    grid = [[0,1],[2,0]]
    k = 1
    print(s.maxPathScore(grid,k))
