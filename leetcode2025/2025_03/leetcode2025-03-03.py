class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        cost = [[0]*n for _ in range(n)]
        # 定义cost[i][j]表示将s[i:j+1]转化为回文串的最少操作次数。根据定义可知，cost[i][j]可以由一个更小的问题转换过来，即cost[i+1][j+1]，将s[i:j-1]转化为回文串首先找到将s[i+1:j-1]转化为回文串，然后再考虑s[i]和s[j]是否相等，如果相等，cost[i][j] = cost[i+1][j-1]，否则cost[i][j] = cost[i+1][j-1]+1
        # 这里要注意，因为计算cost[i][j]需要用到cost[i+1][j-1]，所以我们需要保证在计算时先算i+1再算i，先算j-1再算j，这就需要我们倒序遍历i，同时正序遍历j
        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                cost[i][j] = cost[i+1][j-1]+(0 if s[i]==s[j] else 1)
        # 接下来计算答案。定义dp[i][j]表示将前i个元素分成j个回文串所需的最小操作次数。我们可以将前i个字符分成两段考虑，中间的界限为i0，现在我们要将s[i0:i]作为j个回文串的最后一个串，那么将前i个元素分为j个回文串的操作次数就是：将前i0个元素分为j-1个回文串的操作次数加上把s[i0:i]变成回文串的操作次数。最后在0到i中循环i0计算出dp[i][j]的最小值即可
        # 同时要注意，当j=1时，即将前i个元素分成1个回文串时，直接将dp[i][j]置为cost[0][i-1]即可，并且当j>i时不要去计算dp[i][j]，这时候的i,j没有意义
        dp = [[float("inf")]*(k+1) for _ in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,min(k,i)+1):
                if j == 1:
                    dp[i][j] = cost[0][i-1]
                for i0 in range(1,i):
                    dp[i][j] = min(dp[i][j], dp[i0][j-1]+cost[i0][i-1])
        return dp[n][k]

if __name__ == "__main__":
    sl = Solution()
    s = "abc"
    k = 2
    print(sl.palindromePartition(s,k))
