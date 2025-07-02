class Solution:
    def climbStairs(self, n: int) -> int:
        # 动态规划，定义dp[i]表示到达第i级台阶的总方法数，答案就是dp[n]
        # 然后初始化，dp[0]表示到达第0级台阶的方法数，只有一种，dp[1]表示到达第1级台阶的方法数，可以走一级台阶，因此也只有一种
        # 接下来递推关系式，因为每一级台阶都可能从前一个或前两个跳转过来，因此dp[i]=dp[i-1]+dp[i-2]，当且仅当i>=2时有效
        dp = [0]*(n+1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n+1):
            dp[i] = dp[i-1]+dp[i-2]
        return dp[n]

if __name__ == "__main__":
    s = Solution()
    n = 4
    print(s.climbStairs(n))
