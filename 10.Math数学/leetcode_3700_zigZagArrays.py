modNum = 1_000_000_007

def matrixMultiply(a, b):
    n, m = len(a), len(b[0])
    c = [[0]*m for _ in range(n)]
    for i in range(n):
        for k in range(len(a[0])):
            if a[i][k] == 0:
                continue
            for j in range(m):
                c[i][j] = (c[i][j]+a[i][k]*b[k][j])%modNum
    return c

def quickPow(mat, x, dp):
    res = dp
    while x:
        if x&1:
            res = matrixMultiply(mat, res)
        mat = matrixMultiply(mat, mat)
        x >>= 1
    return res

class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        # 为了简便计算，可以将l和r都减少l，使区间变为[0,r-l]，这和原有情况是等价的
        # 和第一题一样，这道题同样可以定义两个动态规划数组如下：
        #   1.dp0[i][j]表示数组长度为i且第i个数字为j时，最后两个数字呈上升趋势的情况下，数组的总数量
        #   2.dp1[i][j]表示数组长度为i且第i个数字为j时，最后两个数字呈下降趋势的情况下，数组的总数量
        # 这样，同样可以得到和第一题一样的递推公式：
        #   dp0[i][j] = sum(dp1[i-1][k] for k in range(j))
        #   dp1[i][j] = sum(dp0[i-1][k] for k in range(j+1, r-l+1))
        # 因此，如果将dp0和dp1合并成一个长度为2*(r-l+1)的数组dp，那么每一个dp[i]其实都可以用同一套公式从dp[i-1]中得到，此时，将这一套公式即可总结成一个二维矩阵，每次将这个矩阵乘以dp，即可得到下一个dp数组
        k = r-l+1
        mat = [[0]*(2*k) for _ in range(2*k)]
        for i in range(k):
            for j in range(i):
                mat[i][j+k] = 1
            for j in range(i+1, k):
                mat[i+k][j] = 1
        
        dp = [[1] for _ in range(2*k)]
        resMat = quickPow(mat, n-1, dp)

        res = 0
        for row in resMat:
            res = (res+row[0])%modNum
        return res

if __name__ == "__main__":
    s = Solution()
    n, l, r = 3, 4, 5
    print(s.zigZagArrays(n, l, r))
