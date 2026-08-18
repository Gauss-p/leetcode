from typing import List
from collections import Counter

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        if k == 1:
            return max([k for k,v in Counter(nums).items() if v==1]+[-1])
        if len(nums) == k:
            return max(nums)

        res = -1
        if nums.count(nums[0]) == 1:
            res = max(res, nums[0])
        if nums.count(nums[-1]) == 1:
            res = max(res, nums[-1])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,9,2,1,7]
    k = 3
    print(s.largestInteger(nums, k))
