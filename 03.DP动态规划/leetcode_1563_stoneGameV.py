from typing import List

class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        # 当k∈[i+1,p]中时，dp[i][j] = max(dp[i][k]+preSum[k]-preSum[i]) = -preSum[i]+max(dp[i][k]+preSum[k])
        # 当k∈[q,j]中时，dp[i][j] = max(dp[k][j]+preSum[j]-preSum[k]) = preSum[j]+max(dp[k][j]-preSum[k])
        n = len(stoneValue)
        dp = [[0]*(n+1) for _ in range(n)]
        preSum = [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+stoneValue[i]
        sufMax = [[-10**18]*(n+1) for _ in range(n+1)] # 倒序处理，需要用二维数组保存

        for i in range(n-1, -1, -1):
            sufMax[i][i+1] = -preSum[i] # 初始化当前sufMax计算基准
            k = i+1 # 题目要求分出来的左右部分不能为空，故k最小为i+1
            preMax = 0 # 动态维护一个数字即可
            for j in range(i+2, n+1): # 题目要求分出的右边不能为空，故j最小为i+2，需要留两个位置
                while preSum[k]-preSum[i] <= preSum[j]-preSum[k]:
                    preMax = max(preMax, dp[i][k]+preSum[k]) # 它需要一直更新到k
                    k += 1
                # 结束时必有：preSum[k]-preSum[i] > preSum[j]-preSum[k]
                # 且preMax处理到k-1，恰好为论述中的preMax[i][p]
                q = k # k为p+1，如果k倒退一个位置使得两边和相等，那么q就应当为p，即k-1
                if preSum[k-1]-preSum[i] == preSum[j]-preSum[k-1]:
                    q -= 1
                dp[i][j] = max(dp[i][j], -preSum[i]+preMax, preSum[j]+sufMax[q][j])
                sufMax[i][j] = max(sufMax[i+1][j], dp[i][j]-preSum[i]) # 维护sufMax数组
        return dp[0][n]

if __name__ == "__main__":
    s = Solution()
    stoneValue = [6,2,3,4,5,5]
    print(s.stoneGameV(stoneValue))
