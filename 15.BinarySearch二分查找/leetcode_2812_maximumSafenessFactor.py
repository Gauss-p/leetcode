from typing import List
from functools import *

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        # 基本思路如下：
        #   1.根据最初的所有小偷位置得到每个其他位置的安全系数(距离最近的小偷的曼哈顿距离)
        #   2.考虑二分查找，限定安全系数的最小值在所有可行位置中查看是否存在从(0,0)到(n-1,n-1)的通路：
        #       a.如果存在，则说明当前限定的最小值太小了，需更改左端点
        #       b.如果不存在，则说明当前限定的最小值太大了，需更改右端点
        #   3.在判断是否存在通路的地方，可以用dfs进行判断。
        n = len(grid)
        score = [[-1]*n for _ in range(n)]
        q = []
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i,j))
                    score[i][j] = 0

        dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        while q:
            q2 = set()
            for x,y in q:
                for dx,dy in dirs:
                    nx, ny = x+dx, y+dy
                    if nx<0 or nx>=n or ny<0 or ny>=n or score[nx][ny]!=-1:
                        continue
                    score[nx][ny] = score[x][y]+1
                    q2.add((nx,ny))
            q = list(q2)
        
        visited = [[0]*n for _ in range(n)]
        @cache
        def check(x, y, mid):
            if x == n-1 and y == n-1:
                return True
            ans = False
            visited[x][y] = 1
            for dx,dy in dirs:
                nx, ny = x+dx, y+dy
                if nx<0 or nx>=n or ny<0 or ny>=n or visited[nx][ny] or score[nx][ny]<mid:
                    continue
                ans |= check(nx, ny, mid)
            visited[x][y] = 0
            return ans
        
        l, r = 0, min(score[0][0], score[n-1][n-1])
        while l<=r:
            mid = (l+r)//2
            if check(0, 0, mid):
                l = mid+1
            else:
                r = mid-1
            check.cache_clear()
        return r

if __name__ == "__main__":
    s = Solution()
    grid = [[1,0,0],[0,0,0],[0,0,1]]
    print(s.maximumSafenessFactor(grid))
