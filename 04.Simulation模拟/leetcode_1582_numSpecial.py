from typing import List

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        colSum = [0]*n
        rowSum = [0]*m
        for i in range(m):
            for j in range(n):
                rowSum[i] += mat[i][j]
                colSum[j] += mat[i][j]
        
        res = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == rowSum[i] == colSum[j] == 1:
                    res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    mat = [[1,0,0],[0,0,1],[1,0,0]]
    print(s.numSpecial(mat))
