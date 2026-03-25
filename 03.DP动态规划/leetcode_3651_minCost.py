from typing import List
from heapq import *

class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        # 定义dp[c][i][j]表示在c次跳转的情况下，从(0,0)到达(i,j)的最小成本，那么考虑状态转移方程，首先是最容易的两种，即普通移动，在这种情况下，位置(i+1, j+1)要么从(i, j+1)转移而来，要么从(i+1, j)转移而来，而又因为普通移动不需要消耗传送的次数，因此对于任意一个c值，都有：dp[c][i+1][j+1] = min(dp[c][i][j+1], dp[c][i+1][j])+grid[i+1][j+1]
        # 接下来考虑传送，可以发现，如果要上一次操作使用传送，并且要使路径总成本最小，那么我们需要找到grid所有元素中：值大于等于grid[i][j]的所有位置中，在dp[c-1]对应的值最小的那个路径成本。为此，我们可以创建一个数组sufMin，其中sufMin[c][a]表示在所有能够满足grid[x][y]>=a的位置(x,y)中，grid[x][y]的最小值。因此，sufMin[c]的索引范围应当和grid中所有元素的最大值相同，令mx等于grid中所有数字最大值，那么len(sufMin[c])=mx+1，但由于我们要求后缀最小值，计算sufMin[c][a]=min(sufMin[c][a+1], ...)时可能索引到mx+1，因此len(sufMin[c])应为mx+2
        # 那么如何维护sufMin的值呢？我们可以在计算一个dp[c]时同时保存不同的grid中的值对应的dp[c]中的值的最小值，即用另一个列表minF，其中minF[a]表示在所有的grid[x][y]=a的位置(x,y)中，dp[c][x][y]的最小值，这样，我们只需在完全计算完之后倒序遍历所有可能的a值，更新sufMin中的信息即可，而如果这样，sufMin列表就可以只用一维即可，每次在原先的基础之上更新所有信息，即可保证更新完后sufMin保存的信息恰好为原来sufMin[c]中的信息
        # 综上所述，可以发现，如果要传送，我们就需要利用上一次计算出来的sufMin数组，即dp[i+1][j+1] = sufMin[grid[i+1][j+1]]，因此，dp[c][i+1][j+1] = min(min(dp[c][i][j+1], dp[c][i+1][j])+grid[i+1][j+1], sufMin[grid[i+1][j+1]])，同时，根据这个计算顺序，可以发现如果我们先循环c，然后循环i，最后循环j，那么对于每一个c循环中我们只需要使用一个二维的dp数组，甚至如果对于每一个i循环，我们只需要使用一个一维dp数组，每次利用上一行的数据进行更新即可，同时，对于每一个新的c循环，我们都新建一个minF数组记录当前信息，并在ij循环计算完dp[c]中的所有数据之后再对sufMin数组进行维护即可达到上述所有的要求
        n = len(grid[0])
        mx = 0
        for row in grid:
            for x in row:
                if x>mx: # 保存最大值
                    mx = x
        
        sufMin = [float("inf")]*(mx+2)
        for _ in range(k+1):
            minF = [float("inf")]*(mx+1)
            f = [float("inf")]*(n+1)
            f[1] = -grid[0][0] # 这样在计算位置(0,0)时就可以用同样的公式计算出0
            for row in grid:
                for j in range(n):
                    x = row[j]
                    f[j+1] = min(min(f[j], f[j+1])+x, sufMin[x])
                    minF[x] = min(minF[x], f[j+1]) # 保存当前信息
            
            for i in range(mx, -1, -1):
                sufMin[i] = min(sufMin[i+1], minF[i]) # 更新最新数据
        return f[n]

        #==============================================================================

        # 将grid压缩成一维列表，用一维列表中的索引即可直接表示各个点
        # 之后采用dijkstra算法，寻找从0到m*n-1的最短路径，由于k的限制，我们需要知道不同的点在使用不同次数跳转时能够获得的最短路径，因此dist数组需要新增一个变量，范围为0到k，表示使用跳转的次数
        # 对于每一个位置，首先可以更新它左侧和下侧的点的距离，然后，如果当前得到的最短路径对应的跳转次数还没有超过k，我们就可以继续跳转；注意在跳转的时候，我们需要找到值小于grid[x][y]的所有位置，因此可以先将grid压缩成一维列表排序，然后从头到尾查找即可，不过这一步可以进行优化，即对于每一个跳转次数，我们都记录一个它上次跳转到的位置，那么在这一次跳转中，之前已经判断过的位置就无需再次查找，直接从上次查找到的最后一个位置开始向后找即可
        # m, n = len(grid), len(grid[0])
        # stl = []
        # for i in range(m):
        #     for j in range(n):
        #         stl.append((grid[i][j], i*n+j))
        # stl.sort()
        # # print(stl)

        # dist = [[float("inf")]*(k+1) for _ in range(m*n)]
        # dist[0][0] = 0
        # q = [(0, 0, 0)]
        # ptrs = [0]*(k+1)
        # # visited = [[0]*(k+1) for _ in range(m*n)]
        # while q:
        #     d, usedK, pos = heappop(q)
        #     x, y = pos//n, pos%n
        #     if x == m-1 and y == n-1:
        #         return d

        #     for dx,dy in [(0,1),(1,0)]:
        #         nx, ny = x+dx, y+dy
        #         if nx>=m or ny>=n:
        #             continue
        #         nxt = nx*n+ny
        #         if d+grid[nx][ny] < dist[nxt][usedK]:
        #             dist[nxt][usedK] = d+grid[nx][ny]
        #             heappush(q, (d+grid[nx][ny], usedK, nxt))

        #     if usedK == k:
        #         continue
        #     # indx = stl.bisect_right((grid[x][y]+1, 0))-1
        #     p = ptrs[usedK]
        #     v = grid[x][y]
        #     # print(x, y, indx)
        #     while p<m*n and stl[p][0] <= v:
        #         _, nxt = stl[p]
        #         if d < dist[nxt][usedK+1]:
        #             dist[nxt][usedK+1] = d
        #             heappush(q, (d, usedK+1, nxt))
        #         p += 1
        #     ptrs[usedK] = p
        # # print(dist)
        # return -1

if __name__ == "__main__":
    s = Solution()
    grid = [[1,3,3],[2,5,4],[4,3,5]]
    k = 2
    print(s.minCost(grid, k))
