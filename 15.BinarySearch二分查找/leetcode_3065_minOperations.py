from typing import List
from bisect import *

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return bisect_left(sorted(nums), k)

if __name__ == "__main__":
    s = Solution()
    nums = [2,11,10,1,3]
    k = 10
    print(s.minOperations(nums, k))
