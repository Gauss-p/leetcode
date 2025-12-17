from typing import List

FREE, HOLD, SELL = 0, 1, 2

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        # 定义动态规划数组dp，其中dp[i][j][]表示在前i天中进行最多j笔交易时可以获得的最大收益，分三种状态，dp[i][j][0]表示第i天空仓，即没有持有也没有做空，dp[i][j][1]表示第i天持有，dp[i][j][2]表示第i天正在做空，注意我们这里的交易次数j表示的是普通交易的买入次数或做空交易的卖出次数
        # 接下来考虑三种状态的转移方式：
        # 1.如果第i天空仓，可能是第i-1天空仓，或是第i-1天持有但第i天卖出，或是第i-1天做空但第i天买入，因此dp[i][j][0]=max(dp[i-1][j][0], dp[i-1][j][1]+prices[i], dp[i-1][j][2]-prices[i])，注意，根据交易次数的定义，这里的交易次数不能变化
        # 2.如果第i天持有，可能是第i-1天持有，或是第i-1天空仓但第i天买入，所以dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i])，第二种情况的交易次数变化是因为第i天进行了一次普通交易的买入
        # 3.如果第i天做空，可能是第i-1天做空，或是第i-1天空仓但第i天卖出，所以dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][0]+prices[i])，第二种情况的交易次数变化是因为第i天进行了一次做空交易的卖出
        # 当然还要考虑初始值，如果i=0，那么所有的dp[i][j][0]都是0，所有的dp[i][j][1]都是-prices[0]，因为进行了一次买入，所有的dp[i][j][2]都是prices[0]，因为进行了一次做空交易的卖出；如果j=0，那么所有的dp[i][j][]都是0，无论当前是什么状态，既然没有交易，就没有开销
        n = len(prices)
        dp = [[[0]*3 for _ in range(k+1)] for _ in range(n)]
        for j in range(k+1):
            dp[0][j][HOLD] = -prices[0]
            dp[0][j][SELL] = prices[0]

        for i in range(1, n):
            for j in range(1, k+1):
                dp[i][j][FREE] = max(dp[i-1][j][FREE], dp[i-1][j][HOLD]+prices[i], dp[i-1][j][SELL]-prices[i])
                dp[i][j][HOLD] = max(dp[i-1][j][HOLD], dp[i-1][j-1][FREE]-prices[i])
                dp[i][j][SELL] = max(dp[i-1][j][SELL], dp[i-1][j-1][FREE]+prices[i])

        return dp[n-1][k][FREE]

if __name__ == "__main__":
    s = Solution()
    prices = [1,7,9,8,2]
    k = 2
    print(s.maximumProfit(prices, k))
