from typing import List

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        # 我们可以这样想，对于每一个位置(i,j)，我们来统计以该位置为右下角的合法矩形有多少个。假设我们从当前行开始不断向上查找到第k行，这时需要查找的就是：以(i,j)为右下角，以(k,j)为右上角的所有合法矩形个数，又因为已经限制了一条边，所以个数就应当是最大的合法矩形的另一边长。因此我们需要找到最大的合法矩形。那么由于需要这个矩形的每一行都必须全部是1，因此，我们需要知道一个尽可能小的索引x，使得在每一行中，从x到j都是1，那么我们要求的其实就是：从所有行中的第j个数字开始往左边数，能够数到的最大连续1的个数，这些连续1的个数的最小值
        # 举个例子：对于矩阵[[0, 0, 1, 1], [0, 0, 0, 1], [0, 1, 1, 1]]，以(2,3)为右下角，并且以(0,3)为右上角的最大合法矩形只能是横向长度为1，纵向长度为3，也就是只有一个矩形
        # 因此我们只需要预处理出每一个位置左边的最大连续1的个数，就可以从第i行开始向上循环，不断求连续1的个数的最小值，加入答案即可。注意，只要向上的途中遇到了0，就可以退出循环，因为已经没有必要了
        m, n = len(mat), len(mat[0])
        leftOne = [[0]*n for _ in range(m)] # leftOne[i][j]表示在第i行中，从第j列开始向左最大连续1的个数
        for i in range(m):
            cur = 0
            for j in range(n):
                if mat[i][j] == 1:
                    cur += 1
                else:
                    cur = 0
                leftOne[i][j] = cur
        
        res = 0
        for i in range(m):
            for j in range(n):
                minX = float("inf")
                for k in range(i, -1, -1):
                    if minX == 0:
                        break
                    minX = min(minX, leftOne[k][j]) # 取最小值，也就相当于取交集
                    res += minX # 计入答案
        return res

if __name__ == "__main__":
    s = Solution()
    mat = [[1,0,1],[1,1,0],[1,1,0]]
    print(s.numSubmat(mat))
