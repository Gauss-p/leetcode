from typing import List
from bisect import *

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        n = len(nums)
        res = 0
        for i in range(n):
            l = lower-nums[i]
            r = upper-nums[i]
            # 已知nums[i]，那么nums[j]就在[lower-nums[i],upper-nums[i]]的范围内即可
            # 先将nums排序，然后用二分查找即可
            # 注意，为了避免重复计算，j的最小值应该是i+1
            leftIndx = max(i+1, bisect_left(nums, l))
            rightIndx = bisect_right(nums, r)-1
            res += max(0, rightIndx-leftIndx+1)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [0,1,7,4,4,5]
    lower, upper = 3, 6
    print(s.countFairPairs(nums, lower, upper))
