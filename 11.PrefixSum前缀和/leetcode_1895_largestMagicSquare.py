from typing import List

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        rowPreSum = [[0]*(n+1) for _ in range(m)]
        colPreSum = [[0]*n for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                x = grid[i][j]
                rowPreSum[i][j+1] = rowPreSum[i][j]+x
                colPreSum[i+1][j] = colPreSum[i][j]+x
        
        for k in range(min(m, n), 0, -1):
            for i in range(m-k+1):
                for j in range(n-k+1):
                    totSt = set()
                    dia1 = 0
                    dia2 = 0
                    for x in range(k):
                        totSt.add(rowPreSum[i+x][j+k]-rowPreSum[i+x][j])
                        totSt.add(colPreSum[i+k][j+x]-colPreSum[i][j+x])
                        dia1 += grid[i+x][j+x]
                        dia2 += grid[i+x][j+k-1-x]
                    totSt.update([dia1, dia2])
                    
                    if len(totSt) == 1:
                        return k
        return 1

if __name__ == "__main__":
    s = Solution()
    grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
    print(s.largestMagicSquare(grid))
