from typing import List

class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        preSum = [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+prices[i]

        money = [0]*(n+1)
        for i in range(n):
            money[i+1] = money[i]+prices[i]*strategy[i]

        res = money[n]
        for i in range(n-k+1):
            cur = money[i]+(preSum[i+k]-preSum[i+k//2])+(money[n]-money[i+k])
            res = max(res, cur)
        return res

if __name__ == "__main__":
    s = Solution()
    prices = [4,2,8]
    strategy = [-1,0,1]
    k = 2
    print(s.maxProfit(prices, strategy, k))
