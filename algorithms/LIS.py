# https://leetcode.cn/problems/maximize-fixed-points-after-deletions/
# 101056. 删除元素后最大固定点数目

from typing import List
from bisect import *

class Solution:
    def maxFixedPoints(self, nums: list[int]) -> int:
        n = len(nums)
        pairs = []
        for i in range(n):
            if i >= nums[i] and nums[i] < n:
                pairs.append((nums[i], i-nums[i]))
        pairs.sort(key = lambda x:(x[0], -x[1]))

        dp = []
        for _, d in pairs:
            indx = bisect_right(dp, d)
            if indx == len(dp):
                dp.append(d)
            else:
                dp[indx] = d
        return len(dp)

if __name__ == "__main__":
    s = Solution()
    nums = [0,2,1]
    print(s.maxFixedPoints(nums))
