from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        for i in range(1, n):
            for j in range(i+1):
                cur = float("inf")
                if j>0:
                    cur = min(cur, triangle[i-1][j-1])
                if j<i:
                    cur = min(cur, triangle[i-1][j])
                triangle[i][j] += cur
        return min(triangle[-1])

if __name__ == "__main__":
    s = Solution()
    triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    print(s.minimumTotal(triangle))
