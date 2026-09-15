class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        # 定义动态规划数组dp，其中dp[i]表示s[:i]中不重叠回文子字符串的最大数目，因此答案就是dp[n]，接下来考虑状态转移：
        #   1.s[i-1]不算作某个回文子字符串的最后一个字符，那么dp[i] = dp[i-1]
        #   2.s[i-1]作为回文子字符串的结尾，那么需要考虑两个问题：回文串的长度是多少，且字符串后缀能否形成回文串。首先，为了让回文子字符串数量最大化，就要让每个回文串的长度最小化，故对于每一个位置，以它为结尾的回文串只需要考虑长度是k或k+1的两个，分别对应回文串长度是奇数和偶数两种情况。那么如果s[i-k:i]=s[i-k:i][::-1]，即以i-1为结尾，k为长度的字符串是回文的，那么dp[i] = dp[i-k]+1；同理，如果s[i-k-1:i] = s[i-k-1:i][::-1]，那么dp[i] = dp[i-k-1]+1
        n = len(s)
        dp = [0]*(n+1)
        for i in range(k, n+1):
            dp[i] = dp[i-1]
            if s[i-k:i] == s[i-k:i][::-1]:
                dp[i] = max(dp[i], dp[i-k]+1)
            if i>k and s[i-k-1:i] == s[i-k-1:i][::-1]:
                dp[i] = max(dp[i], dp[i-k-1]+1)
        return dp[n]

if __name__ == "__main__":
    sl = Solution()
    s = "abaccdbbd"
    k = 3
    print(sl.maxPalindromes(s, k))
