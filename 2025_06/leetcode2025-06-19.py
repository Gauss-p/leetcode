from typing import List
from bisect import *

class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        i = 0
        res = 0
        while i<n:
            i = bisect_right(nums, nums[i]+k)
            res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,6,1,2,5]
    k = 2
    print(s.partitionArray(nums, k))
