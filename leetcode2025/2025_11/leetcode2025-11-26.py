from typing import List
from functools import *

class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        # 暴力模拟所有路径，统计其中路径和是k的倍数的路径总数即可
        modNum = 1_000_000_007
        m, n = len(grid), len(grid[0])
        dirs = [(0,1), (1,0)]
        @cache
        def dfs(x, y, tot):
            if x==m-1 and y==n-1:
                return int(tot==0)
            ans = 0
            if x<m-1:
                ans = (ans+dfs(x+1, y, (tot+grid[x+1][y])%k))%modNum
            if y<n-1:
                ans = (ans+dfs(x, y+1, (tot+grid[x][y+1])%k))%modNum
            return ans
        res = dfs(0, 0, grid[0][0]%k)
        dfs.cache_clear()
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[5,2,4],[3,0,5],[0,7,2]]
    k = 3
    print(s.numberOfPaths(grid, k))
