from typing import List
from functools import cache
from math import gcd

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        n = len(nums)
        modNum = 1_000_000_007
        @cache
        def dfs(indx, g1, g2):
            if indx == n:
                if g1 == g2:
                    return 1
                return 0
            return (dfs(indx+1, gcd(g1, nums[indx]), g2)+dfs(indx+1, g1, gcd(g2, nums[indx]))+dfs(indx+1, g1, g2))%modNum
        return dfs(0, 0, 0)-1 # 减去「两个空序列相等」的情况

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4]
    print(s.subsequencePairCount(nums))
