from typing import List
from functools import cache

class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        if (m+n-1)%2:
            return False

        val = {'(':1, ')':-1}
        @cache
        def dfs(i, j, cnt):
            if i == m-1 and j == n-1:
                return cnt==0
            if cnt >= (m+n+1)//2:
                return False

            ans = False
            if i<m-1 and cnt+val[grid[i+1][j]] >= 0:
                ans |= dfs(i+1, j, cnt+val[grid[i+1][j]])
            if j<n-1 and cnt+val[grid[i][j+1]] >= 0:
                ans |= dfs(i, j+1, cnt+val[grid[i][j+1]])
            return ans
            
        return dfs(0, 0, 1) if grid[0][0]=='(' and grid[-1][-1]==')' else False

if __name__ == "__main__":
    s = Solution()
    grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
    print(s.hasValidPath(grid))
