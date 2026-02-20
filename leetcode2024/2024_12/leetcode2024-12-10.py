class Solution:
    def knightDialer(self, n: int) -> int:
        neibors = [[4,6],[6,8],[7,9],[4,8],[3,9,0],[],[1,7,0],[2,6],[1,3],[2,4]]
        # 定义dp[i][j]表示第i步走到数字j的位置时的总方案数
        dp = [[0]*10 for _ in range(n+1)]
        modNum = 1_000_000_007
        for i in range(10):
            dp[1][i] = 1
        for i in range(2,n+1):
            for j in range(10):
                for k in neibors[j]:
                    dp[i][j] = (dp[i][j]+dp[i-1][k])%modNum
        return sum(dp[n]) % modNum

if __name__ == "__main__":
    s = Solution()
    n = 3131
    print(s.knightDialer(n))
