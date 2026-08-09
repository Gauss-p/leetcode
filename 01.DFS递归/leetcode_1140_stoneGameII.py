from typing import List
from functools import cache

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        sufSum = [0]*(n+1)
        for i in range(n-1, -1, -1):
            sufSum[i] = sufSum[i+1]+piles[i]
        
        @cache
        def dfs(indx, m):
            if indx+2*m >= n:
                return sufSum[indx]
            cur = 10**18 # 为了让当前选手拿到石子最多，必须让下一个拿到的最少
            for x in range(1, 2*m+1):
                cur = min(cur, dfs(indx+x, max(m, x)))
            return sufSum[indx]-cur
        
        return dfs(0, 1)

if __name__ == "__main__":
    s = Solution()
    piles = [2,7,9,4,4]
    print(s.stoneGameII(piles))
