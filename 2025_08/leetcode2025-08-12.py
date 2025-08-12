from typing import List

powers = [[] for _ in range(6)]
for b in range(1,6):
    a = 1
    while pow(a, b) <= 300:
        powers[b].append(pow(a, b))
        a += 1

class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        # 0-1背包问题，可以先根据数据规模预处理出所有小于300的各个数字的x次方的值，然后根据给出的x进行寻找，找出所有能够使和等于给出的n的方案数量即可
        # 定义dp[i][j]表示在所有的x次方的数字中，前j个数字中能够组成和为i的数字的总方案数量
        # 那么如果选择powers[x][j]，则dp[i][j]=dp[i-1][j-powers[x][i]]，如果不选，则dp[i][j]=dp[i-1][j]
        dp = [[0]*(n+1) for _ in range(len(powers[x])+1)]
        for i in range(len(powers[x])):
            if powers[x][i] > n:
                continue
            dp[i+1][powers[x][i]] = 1

        modNum = 1_000_000_007
        for i in range(1, len(powers[x])+1):
            for j in range(1, n+1):
                dp[i][j] = (dp[i][j]+dp[i-1][j])%modNum
                if j>powers[x][i-1]:
                    dp[i][j] = (dp[i][j]+dp[i-1][j-powers[x][i-1]])%modNum
        
        return dp[len(powers[x])][n]

if __name__ == "__main__":
    s = Solution()
    n = 10
    x = 2
    print(s.numberOfWays(n, x))
