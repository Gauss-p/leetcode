from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # 动态规划，定义dp[i]表示支付第i级台阶的费用后的最小花费，注意是要支付第i级台阶的费用后，那么如果要上到第n级台阶，就需要先走到第n-1或第n-2级台阶，也就需要付第n-1或第n-2级台阶的费用，因此答案就是min(dp[i-1], dp[i-2])
        # 然后初始化，因为我们可以从第0级或第1级台阶开始爬楼梯，所以起点就可以有两个，一个是dp[0]，它的值就应该是cost[0]，因为直接从它开始，前面不需要先走哪一个，另一个是dp[1]，由于可能从第0级爬上来或从第1级直接开始，所以答案就是min(cost[0], 0)+cost[1]
        # 接下来递推关系式，如果要上到第i级台阶，要么先上到第i-1级台阶然后付费，要么上到第i-2级台阶然后付费，因此dp[i]=min(dp[i-1]+dp[i-2])+cost[i]
        n = len(cost)
        dp = [0]*n
        dp[0] = cost[0]
        dp[1] = min(cost[0], 0)+cost[1]
        for i in range(2, n):
            dp[i] = min(dp[i-1], dp[i-2])+cost[i]
        return min(dp[n-1], dp[n-2])

if __name__ == "__main__":
    s = Solution()
    cost = [10,15,20]
    print(s.minCostClimbingStairs(cost))
