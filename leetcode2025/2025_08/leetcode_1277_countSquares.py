from typing import List

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        # 用前缀和的方法，定义preSum[i+1][j+1]表示在matrix中以点(i,j)为右下角，以(0,0)为左上角的方块中间所有数字的和，那么可以知道，preSum[i+1][j+1] = preSum[i][j+1]+preSum[i+1][j]+matrix[i][j]-preSum[i][j]，其中最后一次减是因为前面两次加的时候有重合部分
        # 然后对于每一个位置开始，我们以它为左上角，然后循环一个边长k，表示正方形的边长，这样我们就可以知道右下角的点在哪里，然后借用preSum中的数据就可以快速求出该正方形内部所有数字之和，如果和等于k**2，就说明里面全部都是1，答案加1，否则，只要在循环k的过程中遇到一个不满足和等于k**2的情况，就直接退出循环，因为就算继续往右下扩展还是不行
        m, n = len(matrix), len(matrix[0])
        preSum = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                preSum[i][j] = preSum[i-1][j]+preSum[i][j-1]+matrix[i-1][j-1]-preSum[i-1][j-1]
        
        res = 0
        for i in range(1, m+1):
            for j in range(1, n+1):
                k = 0
                while i+k<=m and j+k<=n:
                    ni, nj = i+k, j+k # 右下角端点
                    curSum = preSum[ni][nj]-preSum[ni][j-1]-preSum[i-1][nj]+preSum[i-1][j-1] # 正方形内部所有数字之和
                    if curSum < (k+1)*(k+1):
                        break
                    if curSum == (k+1)*(k+1):
                        res += 1
                    k += 1
        return res

if __name__ == "__main__":
    s = Solution()
    matrix = [[0,1,1,1],[1,1,1,1],[0,1,1,1]]
    print(s.countSquares(matrix))
