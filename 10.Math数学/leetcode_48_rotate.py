from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        # 将一个矩阵顺时针旋转90度，相当于将它先沿右上-左下对角线翻转，然后再将它上下翻转
        # 旋转90度：matrix[x][y] = matrix[y][n-x-1]
        # 对角线翻转：matrix[x][y] = matrix[n-y-1][n-x-1]
        # 上下翻转：matrix[x][y] = matrix[n-x-1][y]
        # 后面两种翻转合并即可得到：matrix[x][y] = matrix[n-(n-y-1)-1][n-x-1] = matrix[y][n-x-1]，即为所求
        n = len(matrix)
        for x in range(n):
            for y in range(n-x):
                nx, ny = n-y-1, n-x-1
                matrix[nx][ny], matrix[x][y] = matrix[x][y], matrix[nx][ny]
        for x in range(n//2):
            matrix[x], matrix[n-x-1] = matrix[n-x-1], matrix[x]

if __name__ == "__main__":
    s = Solution()
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    s.rotate(matrix)
    print(matrix)
