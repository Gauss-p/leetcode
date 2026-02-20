from typing import List

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # 定义dp[i][j][k]表示在前i个字符串中，最多有i个0和j个1的子集的最大长度。假设str[i]中有zeros个0和ones个1，那么如果我们要在子集中选择第i个字符串，我们就需要在前i-1个字符串中选择最多有j-zeros个0和k-ones个1的子集，因此可以得到：dp[i][j][k] = dp[i-1][j-zeros][k-ones]+1，但是如果不选择第i个字符串，则有：dp[i][j][k] = dp[i-1][j][k]，综上，可得：dp[i][j][k] = max(dp[i-1][j-zeros][k-ones]+1, dp[i-1][j][k])
        # 在实际编码的时候可以将第一维缩减掉，因为每一次的计算只和上一次的计算有关，但是如果缩减掉第一维，为了防止新数据覆盖原数据，就需要倒序遍历计算
        length = len(strs)
        dp = [[0]*(n+1) for _ in range(m+1)]
        for s in strs:
            zeros = s.count('0')
            ones = len(s)-zeros
            for j in range(m, zeros-1, -1):
                for k in range(n, ones-1, -1):
                    if dp[j-zeros][k-ones]+1 > dp[j][k]:
                        dp[j][k] = dp[j-zeros][k-ones]+1
        return dp[m][n]

if __name__ == "__main__":
    s = Solution()
    strs = ["10","0001","111001","1","0"]
    m, n = 5, 3
    print(s.findMaxForm(strs, m, n))
