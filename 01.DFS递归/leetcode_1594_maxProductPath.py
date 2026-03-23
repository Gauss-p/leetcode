from typing import List
from functools import cache

class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        modNum = 1_000_000_007
        @cache
        def dfs(i, j, prod):
            if i == m-1 and j == n-1:
                return -1 if prod<0 else prod
            if prod == 0:
                return prod
            ans = -1
            if i+1<m:
                ans = max(ans, dfs(i+1, j, prod*grid[i+1][j]))
            if j+1<n:
                ans = max(ans, dfs(i, j+1, prod*grid[i][j+1]))
            return ans
        
        res = dfs(0, 0, grid[0][0])
        return -1 if res==-1 else res%modNum

if __name__ == "__main__":
    s = Solution()
    grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
    print(s.maxProductPath(grid))
