from typing import List

class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        # 在循环中，rods[j]始终维护第j列从当前行往上数连续1的个数，那么只需要对这些1的个数排序，即可贪心地求得以当前行为底边的最大矩形面积
        m, n = len(matrix), len(matrix[0])
        res = 0
        rods = [0]*n
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    rods[j] = 0
                else:
                    rods[j] += 1
            
            sortedRods = sorted(rods)
            for k in range(n):
                res = max(res, (n-k)*sortedRods[k])
        return res

if __name__ == "__main__":
    s = Solution()
    matrix = [[0,0,1],[1,1,1],[1,0,1]]
    print(s.largestSubmatrix(matrix))
