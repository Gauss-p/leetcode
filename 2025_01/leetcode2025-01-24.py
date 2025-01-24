from typing import List

class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [float("inf")]*n
        for i in range((n+1)//2-1, n):
            dp[i] = prices[i]
        for i in range((n+1)//2-1, 0, -1):
            dp[i-1] = prices[i-1]+min(dp[i:2*i+1])
        return dp[0]

if __name__ == "__main__":
    s = Solution()
    prices =[1,10,1,1]
    print(s.minimumCoins(prices))
