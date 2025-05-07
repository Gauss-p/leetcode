from typing import List
from heapq import *

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        # 最短路径，每次从已经记录的时间最小的位置出发寻找，并记录每一次的更小时间
        m, n = len(moveTime), len(moveTime[0])
        q = []
        q.append((0,0,0))
        length = [[float("inf")]*n for _ in range(m)]
        length[0][0] = 0
        vis = [[0]*n for _ in range(m)]
        dirs = [(0,1),(0,-1),(1,0),(-1,0)]
        while q:
            t, x, y = heappop(q)
            if vis[x][y] != 0:
                continue
            vis[x][y] = 1
            for dx,dy in dirs:
                nx, ny = x+dx, y+dy
                if nx >= m or ny >= n or nx < 0 or ny < 0:
                    continue
                if vis[nx][ny]:
                    continue
                nt = max(t, moveTime[nx][ny])+1
                if nt<length[nx][ny]:
                    length[nx][ny] = nt
                    heappush(q, (nt, nx, ny))
        return length[m-1][n-1]

if __name__ == "__main__":
    s = Solution()
    moveTime = [[0,4],[4,4]]
    print(s.minTimeToReach(moveTime))
