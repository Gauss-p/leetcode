from typing import List
from heapq import *

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        # 由于对于每一个中间的位置，我们都需要判断其四周所有元素的最值来确定它的存水量，因此采用Dijkstra的思想，先从四周边边上的点开始查找，这些点无论如何是存不了水的，所以从它们开始向中间逼近，即可得到每一个点四周的最值
        # 用一个小顶堆存储各个点的信息，第一个为该点的最小水位高度，第二和第三个分别为该点的坐标，这样，每一次优先处理的都是高度最小的点。为什么要这样处理呢？因为当先处理高度最小的点时，我们就可以更方便地标记内部比它更大的点，而对于这些点而言，因为有了外部一个比它更小的点，所以它们所存的水一定会流向外部
        # 最后，对于每一个弹出的点，都对它周边的所有点进行记录最大水位高度，如果水位高度大于旁边点的高度，就说明旁边这个点一定可以存水，因此加入答案即可
        m, n = len(heightMap), len(heightMap[0])
        visited = [[0]*n for _ in range(m)]
        h = []
        for i in range(m):
            for j in range(n):
                if i==0 or i==m-1 or j==0 or j==n-1:
                    heappush(h, (heightMap[i][j], i, j)) # 加入四周的点
                    visited[i][j] = 1
        
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]] # 四个方向判断
        res = 0
        while h:
            curH, x, y = heappop(h)
            for dx, dy in dirs:
                nx, ny = x+dx, y+dy
                if nx<0 or nx>=m or ny<0 or ny>=n or visited[nx][ny]==1:
                    continue
                if curH > heightMap[nx][ny]:
                    res += curH-heightMap[nx][ny] # 可以存水
                visited[nx][ny] = 1
                heappush(h, (max(curH, heightMap[nx][ny]), nx, ny)) # 更新周围点的水位高度
        return res

if __name__ == "__main__":
    s = Solution()
    heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
    print(s.trapRainWater(heightMap))
