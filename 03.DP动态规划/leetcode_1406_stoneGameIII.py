from typing import List

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [-10**18]*(n+1) # 定义dp[i]表示在stoneValue[i:]中当前玩家的最大得分，故从i开始可以选前1,2或3个数字相加，并将之后一个位置对应的dp值减掉即可得到dp[i]
        dp[n] = 0
        for i in range(n-1, -1, -1):
            if i+1 <= n:
                dp[i] = max(dp[i], stoneValue[i]-dp[i+1])
            if i+2 <= n:
                dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]-dp[i+2])
            if i+3 <= n:
                dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3])
        state = dp[0]
        if state>0:
            return "Alice"
        if state<0:
            return "Bob"
        return "Tie"

if __name__ == "__main__":
    s = Solution()
    stoneValue = [1,2,3,7]
    print(s.stoneGameIII(stoneValue))
