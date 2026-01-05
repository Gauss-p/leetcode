from typing import List

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        neg = -float("inf")
        cnt = 0
        res = 0
        for i in matrix:
            for j in i:
                if j<0:
                    cnt += 1
                res += abs(j)
                if -abs(j) > neg:
                    neg = -abs(j)
        return res if cnt%2 == 0 else res+2*neg

if __name__ == "__main__":
    s = Solution()
    matrix = [[1,-1],[-1,1]]
    print(s.maxMatrixSum(matrix))
