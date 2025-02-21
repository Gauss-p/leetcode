from typing import List

class Solution:
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
        floor = list(map(int, list(floor)))
        n = len(floor)
        # 定义dp[i][j]表示一共有i张地毯，铺在前j个地砖上，未被覆盖的白色砖块的最少个数
        # 所以对于每一个dp[i][j]有两种情况，首先，不铺在第j个地砖，即dp[i][j-1]+(floor[j-1]=='1')，之所以加后边这个是因为当前第j个地砖上没有地毯，如果该地砖是白色，答案就应加1。其次，在当前地砖编号大于一块地毯的长度时，就可以选择铺在第j个地砖上，那么在当前地毯的前面至少也要到j-carpetLen的位置了，所以当前答案即为dp[i-1][j-carpetLen]
        # 还有一些边界情况，如果i=0，没有地毯，答案就是前j个砖中白色的个数;如果j=0，没有地砖，答案就是0;如果i*carpetLen>=j，说明当前地毯一定可以将所有的地砖覆盖，答案也是0
        dp = [[float("inf")]*(n+1) for _ in range(numCarpets+1)]
        dp[0][0] = 0
        # 边界情况
        for j in range(1,n+1):
            # 没有地毯
            dp[0][j] = dp[0][j-1]+floor[j-1]
        for i in range(1,numCarpets+1):
            # 没有地砖
            dp[i][0] = 0
        for i in range(1,numCarpets+1):
            for j in range(1,n+1):
                # 地毯可覆盖所有砖
                if i*carpetLen >= j:
                    dp[i][j] = 0
        # 计算答案
        for i in range(1,numCarpets+1):
            for j in range(1,n+1):
                dp[i][j] = min(dp[i][j], dp[i][j-1]+floor[j-1])
                if j>=carpetLen:
                    dp[i][j] = min(dp[i][j], dp[i-1][j-carpetLen])
        return dp[numCarpets][n]

if __name__ == "__main__":
    s = Solution()
    floor = "10110101"
    numCarpets, carpetLen = 2, 2
    print(s.minimumWhiteTiles(floor, numCarpets, carpetLen))
