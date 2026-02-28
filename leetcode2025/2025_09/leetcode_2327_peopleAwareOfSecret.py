class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        # 定义dp[i]表示到第i天为止，一共有多少人知道过秘密，注意，这里的“知道过”表示从头到尾只要是知道了一次秘密的人都要算入，因此，最终的答案就应该是dp[n]-dp[n-forget]，需要减去已经忘记秘密的人
        # 接下来递推关系式，首先可以直接转移，得到：dp[i]=dp[i-1]，但是需要注意的是，对于第i天来说，只要是在日期区间(i-forget, i-delay]中知道秘密的人都可以和其他人说，因此我们又可以得到：dp[i] += dp[i-delay]-dp[i-forget]，这样，一直计算到第n天，就可以直接返回答案了
        modNum = 1_000_000_007
        dp = [0]*(n+1)
        dp[1] = 1
        for i in range(2, n+1):
            dp[i] = (dp[i-1]+(dp[i-delay]-dp[i-forget]))%modNum
        return (dp[n]-dp[n-forget]+modNum)%modNum

if __name__ == "__main__":
    s = Solution()
    n = 6
    delay = 2
    forget = 4
    print(s.peopleAwareOfSecret(n, delay, forget))
