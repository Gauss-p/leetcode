from typing import List
from heapq import *

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dirs = [(0,1), (0,-1), (1,0), (-1,0)] # 四个方向
        dis = [[float("inf")]*n for _ in range(n)] # 从(0,0)到各个位置的最短距离
        dis[0][0] = 0
        visited = [[0]*n for _ in range(n)] # 防止重复计算同一个点
        q = [(0, 0, 0)] # 小根堆，每一次都从当前已记录的距离最短的点开始向四周寻找
        while q:
            t, x, y = heappop(q)
            if visited[x][y]:
                continue
            visited[x][y] = 1
            for dx, dy in dirs:
                nx, ny = x+dx, y+dy
                if nx<0 or nx>=n or ny<0 or ny>=n:
                    continue
                cur = max(t, max(grid[x][y], grid[nx][ny])) # 到达(nx,ny)点的用时
                if cur < dis[nx][ny]:
                    dis[nx][ny] = cur
                    heappush(q, (cur, nx, ny))
        return dis[n-1][n-1]

if __name__ == "__main__":
    s = Solution()
    grid = [[0,2],[1,3]]
    print(s.swimInWater(grid))
