from typing import List

class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        def getCircle(x, y, filling=[-1]*(2*m+2*n)):
            originX, originY = x, y
            circle = []
            indx = 0
            for c in range(y, n-y-1):
                circle.append(grid[x][c])
                grid[x][c] = filling[indx]
                indx += 1
            for r in range(x, m-x-1):
                circle.append(grid[r][n-y-1])
                grid[r][n-y-1] = filling[indx]
                indx += 1
            for c in range(n-y-1, y, -1):
                circle.append(grid[m-x-1][c])
                grid[m-x-1][c] = filling[indx]
                indx += 1
            for r in range(m-x-1, x, -1):
                circle.append(grid[r][y])
                grid[r][y] = filling[indx]
                indx += 1
            return circle
        
        circles = []
        for i in range(min(m//2, n//2)):
            circles.append(getCircle(i, i))
        
        for i in range(min(m//2, n//2)):
            cur = circles[i]
            indx = k%len(cur)
            _ = getCircle(i, i, cur[indx:]+cur[:indx])
        return grid

if __name__ == "__main__":
    s = Solution()
    grid = [[40,10],[30,20]]
    k = 1
    print(s.rotateGrid(grid, k))
