from typing import List

class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        cnt = [0]*n
        for i in range(n):
            for j in range(n):
                if j == i:
                    continue
                if items[j][0] % items[i][0] == 0:
                    cnt[i] += 1

        dp = [0]*(budget+1)
        for i, (f, price) in enumerate(items):
            for j in range(budget, price-1, -1):
                dp[j] = max(dp[j], dp[j-price]+cnt[i]+1)
                
            for j in range(price, budget+1):
                if dp[j-price]+1 > dp[j]:
                    dp[j] = dp[j-price]+1
        return dp[budget]

if __name__ == "__main__":
    s = Solution()
    items = [[6, 2], [2, 6], [3, 4]]
    budget = 9
    print(s.maximumSaleItems(items, budget))
