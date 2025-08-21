from typing import List
from heapq import *

class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        # 用dijkstra算法即可解决这个问题。首先我们需要建图，但是注意到题目中提到从每一个点(x,y)出发首先可以到达(x+1,y)和(x,y+1)，因此在while循环中可以直接对两个点进行循环判断即可，不需要用g来建图。但是同时，这个点还可以跳转到其他的在grid中的值小于等于当前值的位置，因此，我们可以定义一个列表cell，其中每一个值都由grid中的值、横坐标和纵坐标三个元素构成，然后将其排序，那么对于其中索引为i的元素(grid[x][y], x, y)，点(x,y)可以跳转到的位置就是cell[:i]中的所有位置，也就是说，在while循环中，不仅需要循环一定可以到达的两个点，还需要循环cell中所有小于当前元素的点
        # 但是如果直接循环肯定太慢(当然太慢，会超时)，因此我们必须要减少循环次数。我们可以这样想，cell中的元素不会变，但假设有两次跳转的时候都是在已经跳了curK次之后的，那么如果这两次跳转选择了跳在同一个位置，是不是就重复计算了呢？这样就没有意义，还会增加循环次数。因此我们可以构建一个列表ptrs，其中ptrs[k]记录的数字代表：之前在已经跳转了k次之后已经跳过的最后一个cell中的元素，那么之后只要是从k次跳转之后开始继续跳转，我们就从ptrs[k]开始继续往后跳转，这样就可以减少循环次数了，同时还避免了不少的重复计算
        # 最后，由于这里面有三个变量：横坐标，纵坐标，跳转次数，所以dist数组就需要变成三维列表，同时q中的所有元素都需要变成四元组，并且在while循环中的跳转中需要注意跳转次数的变化

        m, n = len(grid), len(grid[0])
        dist = [[[float("inf")]*(k+1) for _ in range(n)] for _ in range(m)]
        dist[0][0][0] = 0
        q = [(0,0,0,0)]
        cells = sorted((grid[i][j], i, j) for i in range(m) for j in range(n)) # 将所有元素排出来
        ptrs = [0]*(k+1) # 转移列表

        while len(q):
            curD, curK, x, y = heappop(q)
            if x==m-1 and y==n-1:
                # 只要到达了最右下角的点，就直接返回答案
                return curD
            
            for nx, ny in [(x+1, y), (x, y+1)]:
                # 普通跳转，共两种情况
                if nx<m and ny<n:
                    newDis = curD+grid[nx][ny]
                    if newDis < dist[nx][ny][curK]:
                        dist[nx][ny][curK] = newDis
                        heappush(q, (newDis, curK, nx, ny))

            if curK < k:
                p = ptrs[curK] # 从上一次的最后一个位置开始跳转，避免重复计算
                v = grid[x][y]
                while p<len(cells) and cells[p][0]<=v:
                    _, nx, ny = cells[p]
                    if curD < dist[nx][ny][curK+1]:
                        dist[nx][ny][curK+1] = curD # 注意用了一次跳转，更新的时候就需要将curK+1
                        heappush(q, (curD, curK+1, nx, ny))
                    p += 1
                ptrs[curK] = p # 更新对应的最后一个位置

        return -1

if __name__ == "__main__":
    s = Solution()
    grid = [[1,3,3],[2,5,4],[4,3,5]]
    k = 2
    print(s.minCost(grid, k))
