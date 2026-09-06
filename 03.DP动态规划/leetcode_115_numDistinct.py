class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        # 定义动态规划数组dp，其中dp[i][j]表示在s[:j]的子序列中t[:i]出现的个数，也就是能用s[:j]中的元素拼凑出t[:i]的情况总数，根据定义可以得到状态转移方程如下：
        #   1.在任何情况下，都可以不选s[j]和t[i]进行匹配，因此dp[i][j]至少是dp[i][j-1]
        #   2.当s[j]=t[i]时，可以将s[j]和t[i]进行匹配，因此dp[i][j]需要加上dp[i-1][j-1]
        # 最终答案即为dp[len(t)][len(s)]
        m, n = len(t), len(s)
        dp = [[0]*(n+1) for _ in range(m+1)]
        for j in range(n+1):
            dp[0][j] = 1
        
        for i in range(1, m+1):
            for j in range(i, n+1):
                dp[i][j] = dp[i][j-1]
                if t[i-1] == s[j-1]:
                    dp[i][j] += dp[i-1][j-1]
        
        return dp[m][n]

if __name__ == "__main__":
    sl = Solution()
    s = "rabbbit"
    t = "rabbit"
    print(sl.numDistinct(s, t))
