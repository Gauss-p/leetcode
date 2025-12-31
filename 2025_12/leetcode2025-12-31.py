from typing import List

class UFS:
    def __init__(self, n):
        self.pa = list(range(n))
    
    def find(self, x):
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        self.pa[px] = py
    
    def isSame(self, x, y):
        return self.find(x)==self.find(y)

class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        # 倒序遍历，每次还原一块区域，将其从淹水状态变为陆地状态，然后看是否能够从第一行一直通到最后一行，如果可以，就直接将当前天的编号返回即可，因为在当前天之前的所有时间都一定可以按照要求穿过矩阵
        # 为了判断第一行是否能够到达最后一行，我们需要用到并查集，每次还原完位置(x,y)后，就将它和周边已经变成陆地的位置并到一个集合中，不过需要注意的是，并查集的pa数组是一维的，因此可以将每个位置按照x*col+y的方式转化为一维列表中的编号，然后合并
        # 如果单纯按照这样进行合并，无法高效判断是否存在第一行的某个位置和最后一行的某个位置位于一个集合中，因此可以增加两个哨兵，一个标识第一行，另一个标识最后一行，这样，每次在遇到位于第一行的位置还原时就将它和第一行的标识合并，每次在遇到位于最后一行的位置还原时就将它和最后一行的标识合并，最后只需判断第一行标识和最后一行标识是否在同一个集合中即可
        dirs = ((0,1), (0,-1), (1,0), (-1,0))
        land = [[False]*col for _ in range(row)]
        top, bottom = row*col, row*col+1 # 第一行和最后一行的标识
        ufs = UFS(row*col+2) # 注意加了两个哨兵

        for i in range(len(cells)-1, -1, -1):
            x, y = cells[i][0]-1, cells[i][1]-1
            land[x][y] = True
            cur = x*col+y
            if x == 0:
                ufs.union(cur, top)
            if x == row-1:
                ufs.union(cur, bottom)
            for dx, dy in dirs: # 和相邻陆地合并
                nx, ny = x+dx, y+dy
                nxt = nx*col+ny
                if nx < 0 or nx >= row or ny < 0 or ny >= col or land[nx][ny] == False:
                    continue
                ufs.union(cur, nxt)
            if ufs.isSame(top, bottom):
                return i
        return -1

if __name__ == "__main__":
    s = Solution()
    row = 2
    col = 2
    cells = [[1,1],[2,1],[1,2],[2,2]]
    print(s.latestDayToCross(row, col, cells))
