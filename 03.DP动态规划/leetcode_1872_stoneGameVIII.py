from typing import List

class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        n = len(stones)
        tot = sum(stones)
        mx = tot
        for i in range(n-2, 0, -1):
            tot -= stones[i+1]
            if tot-mx > mx:
                mx = tot-mx
        return mx

        # ===================================

        # n = len(stones)
        # preSum = [0]*(n+1)
        # for i in range(n):
        #     preSum[i+1] = preSum[i]+stones[i]

        # mx = preSum[n]
        # for i in range(n-2, 0, -1):
        #     mx = max(mx, preSum[i+1]-mx)
        # return mx

        # ===================================
        
        # @cache
        # def dfs(pos):
        #     if pos >= n-1:
        #         return 0
        #     diff = -10**18
        #     for i in range(pos+1, n):
        #         diff = max(diff, preSum[i+1]-dfs(i))
        #     return diff
        
        # return dfs(0)

if __name__ == "__main__":
    s = Solution()
    stones = [-1,2,-3,4,-5]
    print(s.stoneGameVIII(stones))
