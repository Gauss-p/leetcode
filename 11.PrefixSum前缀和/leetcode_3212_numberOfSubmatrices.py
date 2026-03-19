from typing import List

class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        preSum = [[[0,0] for _ in range(n+1)] for _ in range(m+1)]
        res = 0
        for i in range(m):
            for j in range(n):
                preSum[i+1][j+1][0] = preSum[i+1][j][0]+preSum[i][j+1][0]-preSum[i][j][0]+(grid[i][j]=='X')
                preSum[i+1][j+1][1] = preSum[i+1][j][1]+preSum[i][j+1][1]-preSum[i][j][1]+(grid[i][j]=='Y')
                if preSum[i+1][j+1][0] == preSum[i+1][j+1][1] and preSum[i+1][j+1][0] != 0:
                    res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [["X","Y","."],["Y",".","."]]
    print(s.numberOfSubmatrices(grid))
