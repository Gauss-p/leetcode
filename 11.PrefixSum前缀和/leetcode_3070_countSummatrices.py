from typing import List

class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        preSum = [[0]*(n+1) for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                preSum[i+1][j+1] = preSum[i+1][j]+preSum[i][j+1]+grid[i][j]-preSum[i][j]
        
        res =  0
        for i in range(m):
            for j in range(n):
                if preSum[i+1][j+1] > k:
                    break
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[7,6,3],[6,6,1]]
    k = 18
    print(s.countSubmatrices(grid, k))
