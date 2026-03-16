from typing import List
from heapq import *

class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        dia1 = [[0]*(n+1) for _ in range(m+1)]
        dia2 = [[0]*(n+2) for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                dia1[i+1][j+1] = dia1[i][j]+grid[i][j]
                dia2[i+1][j+1] = dia2[i][j+2]+grid[i][j]
        
        def exists(x, y):
            return 0<=x and x<m and 0<=y and y<n

        res = [0,0,0]
        for i in range(m):
            for j in range(n):
                if grid[i][j] not in res:
                    heappushpop(res, grid[i][j])
                for k in range(1, min(m, n)):
                    up = (i, j)
                    left = (i+k, j-k)
                    right = (i+k, j+k)
                    down = (i+2*k, j)
                    if any((not exists(x,y)) for x,y in [up,left,right,down]):
                        break
                    s1 = dia2[left[0]+1][left[1]+1]-dia2[up[0]][up[1]+2]
                    s2 = dia1[right[0]+1][right[1]+1]-dia1[up[0]][up[1]]
                    s3 = dia2[down[0]+1][down[1]+1]-dia2[right[0]][right[1]+2]
                    s4 = dia1[down[0]+1][down[1]+1]-dia1[left[0]][left[1]]
                    
                    tot = s1+s2+s3+s4-grid[up[0]][up[1]]-grid[left[0]][left[1]]-grid[right[0]][right[1]]-grid[down[0]][down[1]]
                    if tot not in res:
                        heappushpop(res, tot)
        while res[0] == 0:
            heappop(res)
        return sorted(res, reverse = True)

if __name__ == "__main__":
    s = Solution()
    grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
    print(s.getBiggestThree(grid))
