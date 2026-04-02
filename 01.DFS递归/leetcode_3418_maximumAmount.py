from typing import List
from functools import *

class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        @cache
        def dfs(i, j, k):
            if i == m-1 and j == n-1:
                return coins[i][j] if coins[i][j] >= 0 else (0 if k<2 else coins[i][j])
            if i >= m or j >= n:
                return -float("inf")
            res = -float("inf")
            res = max(res, dfs(i+1, j, k)+coins[i][j])
            res = max(res, dfs(i, j+1, k)+coins[i][j])
            if coins[i][j] < 0 and k < 2:
                res = max(res, dfs(i+1, j, k+1))
                res = max(res, dfs(i, j+1, k+1))
            return res
        ans = dfs(0, 0, 0)
        dfs.cache_clear()
        return ans

if __name__ == "__main__":
    s = Solution()
    coins = [[0,1,-1],[1,-2,3],[2,-3,4]]
    print(s.maximumAmount(coins))
