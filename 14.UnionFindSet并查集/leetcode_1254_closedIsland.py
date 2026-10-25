from typing import List

class UFS:
    def __init__(self, grid):
        m, n = len(grid), len(grid[0])
        self.pa = list(range(m*n))
        self.lands = sum(r.count(0) for r in grid)
        self.unavailable = [0]*(m*n)
        self.cols = n
        self.rows = m
    
    def find(self, x):
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px < py:
            x, y = y, x
            px, py = py, px
        if px != py:
            self.lands -= 1
            self.pa[px] = py
            self.unavailable[py] |= self.unavailable[px]

        if x//self.cols == 0 or x//self.cols == self.rows-1 or x%self.cols == 0 or x%self.cols == self.cols-1:
            self.unavailable[py] = 1

class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        # 并查集，将所有土地连为多块，每一块均根据是否有陆地位于矩阵边界来判定它是否是有效封闭岛屿，最后循环所有位置，统计那些是一个连通块的根节点，并且是有效封闭岛屿的位置即可
        m, n = len(grid), len(grid[0])
        ufs = UFS(grid)
        dirs = [(-1,0), (0,-1), (0,0)]
        for i in range(m):
            for j in range(n):
                cur = i*n+j
                if grid[i][j] == 1:
                    continue
                for dx,dy in dirs:
                    nx,ny = i+dx, j+dy
                    if nx<0 or ny<0:
                        continue
                    if grid[nx][ny] == 0:
                        ufs.union(cur, cur+dx*n+dy)
                        
        res = 0
        for i in range(m*n):
            if ufs.unavailable[i]==0 and ufs.pa[i]==i and grid[i//n][i%n]==0:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
    print(s.closedIsland(grid))
