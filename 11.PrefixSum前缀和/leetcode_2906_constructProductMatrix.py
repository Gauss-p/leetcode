from typing import List

class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        modNum = 12345
        m, n = len(grid), len(grid[0])
        preProd = [1]*(m*n+1)
        sufProd = [1]*(m*n+1)
        for i in range(m):
            for j in range(n):
                indx = i*n+j
                x = grid[i][j]
                preProd[indx+1] = (preProd[indx]*x)%modNum

                indx2 = (m-i-1)*n+(n-j-1)
                x2 = grid[m-i-1][n-j-1]
                sufProd[indx2] = (sufProd[indx2+1]*x2)%modNum
        
        res = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                indx = i*n+j
                res[i][j] = (preProd[indx]*sufProd[indx+1])%modNum
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[1,2],[3,4]]
    print(s.constructProductMatrix(grid))
