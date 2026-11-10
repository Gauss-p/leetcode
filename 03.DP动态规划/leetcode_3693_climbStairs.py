from typing import List

class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        costs.insert(0, 0)
        dp = [float("inf")]*(n+1)
        dp[0] = 0
        for i in range(1, n+1):
            for j in range(1, 4):
                if i-j < 0:
                    break
                if dp[i-j] + costs[i]+(j**2) < dp[i]:
                    dp[i] = dp[i-j] + costs[i]+(j**2)
        return dp[n]

if __name__ == "__main__":
    s = Solution()
    n = 4
    costs = [1,2,3,4]
    print(s.climbStairs(n, costs))
