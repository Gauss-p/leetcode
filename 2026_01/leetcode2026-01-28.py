from typing import List
from heapq import *

class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        # 将grid压缩成一维列表，用一维列表中的索引即可直接表示各个点
        # 之后采用dijkstra算法，寻找从0到m*n-1的最短路径，由于k的限制，我们需要知道不同的点在使用不同次数跳转时能够获得的最短路径，因此dist数组需要新增一个变量，范围为0到k，表示使用跳转的次数
        # 对于每一个位置，首先可以更新它左侧和下侧的点的距离，然后，如果当前得到的最短路径对应的跳转次数还没有超过k，我们就可以继续跳转；注意在跳转的时候，我们需要找到值小于grid[x][y]的所有位置，因此可以先将grid压缩成一维列表排序，然后从头到尾查找即可，不过这一步可以进行优化，即对于每一个跳转次数，我们都记录一个它上次跳转到的位置，那么在这一次跳转中，之前已经判断过的位置就无需再次查找，直接从上次查找到的最后一个位置开始向后找即可
        m, n = len(grid), len(grid[0])
        stl = []
        for i in range(m):
            for j in range(n):
                stl.append((grid[i][j], i*n+j))
        stl.sort()
        # print(stl)

        dist = [[float("inf")]*(k+1) for _ in range(m*n)]
        dist[0][0] = 0
        q = [(0, 0, 0)]
        ptrs = [0]*(k+1)
        # visited = [[0]*(k+1) for _ in range(m*n)]
        while q:
            d, usedK, pos = heappop(q)
            x, y = pos//n, pos%n
            if x == m-1 and y == n-1:
                return d

            for dx,dy in [(0,1),(1,0)]:
                nx, ny = x+dx, y+dy
                if nx>=m or ny>=n:
                    continue
                nxt = nx*n+ny
                if d+grid[nx][ny] < dist[nxt][usedK]:
                    dist[nxt][usedK] = d+grid[nx][ny]
                    heappush(q, (d+grid[nx][ny], usedK, nxt))

            if usedK == k:
                continue
            # indx = stl.bisect_right((grid[x][y]+1, 0))-1
            p = ptrs[usedK]
            v = grid[x][y]
            # print(x, y, indx)
            while p<m*n and stl[p][0] <= v:
                _, nxt = stl[p]
                if d < dist[nxt][usedK+1]:
                    dist[nxt][usedK+1] = d
                    heappush(q, (d, usedK+1, nxt))
                p += 1
            ptrs[usedK] = p
        # print(dist)
        return -1

if __name__ == "__main__":
    s = Solution()
    grid = [[1,3,3],[2,5,4],[4,3,5]]
    k = 2
    print(s.minCost(grid, k))
