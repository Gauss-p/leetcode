from typing import List
from functools import *

class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        modNum = 1_000_000_007
        m, n = len(grid), len(grid[0])
        dirs = [(1,0), (0,1)]
        @cache
        def dfs(x, y, d):
            if x<0 or x>=m or y<0 or y>=n:
                return 0
            if x==m-1 and y==n-1:
                return 1
            ans = 0
            if grid[x][y] == 1:
                ans = (ans+dfs(x+dirs[1-d][0], y+dirs[1-d][1], 1-d))%modNum
            else:
                ans = (ans+dfs(x+dirs[0][0], y+dirs[0][1], 0))%modNum
                ans = (ans+dfs(x+dirs[1][0], y+dirs[1][1], 1))%modNum
            return ans
        res = dfs(0, 0, 0)
        dfs.cache_clear()
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[0,1,0],[0,0,1],[1,0,0]]
    print(s.uniquePaths(grid))
