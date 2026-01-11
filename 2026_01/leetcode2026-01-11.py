from typing import List

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # 如果我们以位置(i,j)为矩形右下角，如何求全1矩形的最大面积？如果矩形只有一行，那么它的宽度就是matrix[i]中j左侧连续1的最大长度，而如果矩形有两行，那么它的最大宽度就是：matrix[i]中j左侧连续1的最大长度和matrix[i-1]中j左侧连续1的最大长度的最小值；以此类推，如果向上找到了第k行，那么矩形最大宽度就是第k行到第i行中，每一行的j左侧连续1的最大长度的最小值。因此，我们可以先求出每一个位置左侧最长连续1的长度，这样，就可以在向上循环的同时找到当前对应的最大宽度了
        myMin = lambda x,y : x if x<y else y
        myMax = lambda x,y : x if x>y else y
        m, n = len(matrix), len(matrix[0])
        leftOnes = [[0]*(n+1) for _ in range(m)] # 每个位置左侧连续1的最大长度
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    leftOnes[i][j+1] = leftOnes[i][j]+1
                else:
                    leftOnes[i][j+1] = 0
        
        res = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '0':
                    continue
                maxLength = float("inf")
                for k in range(i, -1, -1):
                    if maxLength == 0:
                        break
                    maxLength = myMin(maxLength, leftOnes[k][j+1]) # 最大宽度
                    res = myMax(res, maxLength*(i-k+1))
        return res

if __name__ == "__main__":
    s = Solution()
    matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    print(s.maximalRectangle(matrix))
