from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m,n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1:
            # 如果起点和终点有一个是障碍，那么就不存在任何路径
            return 0
        # 定义dp[i][j]表示从[0][0]出发到[i][j]这个位置的不同路径的总数量，答案即为dp[m-1][n-1]
        # 所以每一个dp[i][j]可能从两个方向转移，一个是dp[i-1][j]，另一个是dp[i][j-1]，但是同时要保证转移之前的位置没有障碍，即obstacleGrid[i-1][j]!=1时才可以加dp[i-1][j]，obstacleGrid[i][j-1]!=1时才可以加dp[i][j-1]
        dp = [[0]*n for _ in range(m)]
        # 对于第一行和第一列，在没有遇到第一个障碍之前的所有位置上，都可以将dp对应的位置置为1
        for i in range(m):
            if obstacleGrid[i][0]==1:
                break
            dp[i][0] = 1
        for j in range(n):
            if obstacleGrid[0][j]==1:
                break
            dp[0][j] = 1
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 1:
                    continue
                if obstacleGrid[i-1][j] != 1:
                    dp[i][j] += dp[i-1][j]
                if obstacleGrid[i][j-1] != 1:
                    dp[i][j] += dp[i][j-1]
        return dp[m-1][n-1]

if __name__ == "__main__":
    s = Solution()
    obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    print(s.uniquePathsWithObstacles(obstacleGrid))
