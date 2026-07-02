from typing import List
from heapq import *

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        # 找到最小需要的健康值，和health比较大小即可
        m, n = len(grid), len(grid[0])
        q = [(grid[0][0],0,0)]
        dist = [[10**18]*n for _ in range(m)]
        dist[0][0] = grid[0][0]
        dirs = [(0,1), (0,-1), (1,0), (-1,0)]
        visited = [[0]*n for _ in range(m)]
        while q:
            d, x, y = heappop(q)
            if visited[x][y]:
                continue
            visited[x][y] = 1
            for dx,dy in dirs:
                nx, ny = x+dx, y+dy
                if nx<0 or nx>=m or ny<0 or ny>=n:
                    continue
                curD = d+grid[nx][ny]
                if curD < dist[nx][ny]:
                    dist[nx][ny] = curD
                    heappush(q, (curD, nx, ny))
        
        return dist[m-1][n-1] < health

if __name__ == "__main__":
    s = Solution()
    grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
    health = 1
    print(s.findSafeWalk(grid, health))
