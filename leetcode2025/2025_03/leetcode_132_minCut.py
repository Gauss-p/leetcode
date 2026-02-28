class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        g = [[True]*n for _ in range(n)]
        # 定义g[i][j]表示s[i:j+1]是否为回文串
        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                g[i][j] = (s[i] == s[j] and g[i+1][j-1])
        dp = [float("inf")]*n
        # 定义dp[i]表示将前i个字符分割为全回文串所需的最少分割次数
        for i in range(n):
            if g[0][i]:
                dp[i] = 0
                continue
            for j in range(i):
                # 如果s[j+1:i]是回文串，那么将前i个字符分割的次数就是将前j个字符分割的次数加1
                if g[j+1][i]:
                    dp[i] = min(dp[i], dp[j]+1)
        return dp[n-1]

if __name__ == "__main__":
    sl = Solution()
    s = "aab"
    print(sl.minCut(s))
