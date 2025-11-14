from typing import List

class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        # 定义二维差分数组，我们需要令这个差分数组能够按照二维前缀和的方式还原，因此如果在其中一个位置(i,j)加了1，这个1就会影响到整个矩阵中在该位置右下角的所有值，因此，如果我们要将矩阵(r1,c1, r2,c2)中的所有元素都加上1，我们首先需要将它的左上角元素加上1，然后将这个加1的影响在矩阵外侧彻底消除，为了消除，我们就需要在矩阵的右上角向右一个位置减1，并在矩阵的左下角向下一个位置减1，但是可以发现，这样一来，矩阵的右下角位置向右向下的一个位置(r2+1, c2+1)的位置右下方所有位置都多减了1，因此还需要将这个位置加上1
        # 由于我们在差分矩阵的第一行和第一列都加上了一个全0数组，因此在操作的时候需要将每个位置的索引加1
        # 最后再用二维前缀和的方式将矩阵还原即可
        diff = [[0]*(n+2) for _ in range(n+2)]
        for r1, c1, r2, c2 in queries:
            diff[r1+1][c1+1] += 1
            diff[r1+1][c2+2] -= 1 # 消除影响
            diff[r2+2][c1+1] -= 1
            diff[r2+2][c2+2] += 1 # 补上多减的部分

        res = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                diff[i+1][j+1] = diff[i+1][j+1]+diff[i+1][j]+diff[i][j+1]-diff[i][j] # 前缀和方式还原
                res[i][j] = diff[i+1][j+1]
        return res

if __name__ == "__main__":
    s = Solution()
    n = 3
    queries = [[1,1,2,2],[0,0,1,1]]
    print(s.rangeAddQueries(n, queries))
