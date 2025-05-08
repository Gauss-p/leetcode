from typing import List
from heapq import *

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        # 最短路径，主要思路同题目I相同，但是这里我们需要增加一个标记last，用来标识当前移动时间是1还是2
        # 我们可以用%2运算的性质，每次只需将last加1改变其奇偶性即可
        m, n = len(moveTime), len(moveTime[0])
        length = [[float("inf")]*n for _ in range(m)]
        length[0][0] = 0
        q = [(0,0,0,0)]
        visited = [[0]*n for _ in range(m)]
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]

        while q:
            t, x, y, last = heappop(q)
            if visited[x][y]:
                continue
            visited[x][y] = 1
            for dx,dy in dirs:
                nx,ny = x+dx,y+dy
                if nx<0 or nx>=m or ny<0 or ny>=n:
                    continue
                if visited[nx][ny]:
                    continue
                nt = max(length[x][y], moveTime[nx][ny])
                nt += 1+(last%2)
                if nt<length[nx][ny]:
                    heappush(q, (nt, nx, ny, last+1))
                    length[nx][ny] = nt
        return length[m-1][n-1]

if __name__ == "__main__":
    s = Solution()
    moveTime = [[0,4],[4,4]]
    print(s.minTimeToReach(moveTime))
