from typing import List

class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        dirs = [(0,-1), (0,1), (1,0), (-1,0)]
        def dfs(x, y):
            if x<0 or x>=m or y<0 or y>=n or grid[x][y] == 0:
                return 0
            res = grid[x][y]%k
            grid[x][y] = 0
            res = (res+sum(dfs(x+dx, y+dy) for dx,dy in dirs))%k
            return res
        
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    res += (dfs(i, j)==0)
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]]
    k = 5
    print(s.countIslands(grid, k))
