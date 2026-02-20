from typing import List

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        preSum = [[0]*(n+1) for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                preSum[i+1][j+1] = preSum[i][j+1]+preSum[i+1][j]-preSum[i][j]+mat[i][j]
        
        for k in range(min(m, n), 0, -1):
            for i in range(m-k+1):
                for j in range(n-k+1):
                    cur = preSum[i+k][j+k]-preSum[i][j+k]-preSum[i+k][j]+preSum[i][j]
                    if cur <= threshold:
                        return k
        return 0

if __name__ == "__main__":
    s = Solution()
    mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]
    threshold = 4
    print(s.maxSideLength(mat, threshold))
