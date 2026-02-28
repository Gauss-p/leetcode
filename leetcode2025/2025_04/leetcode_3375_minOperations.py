from typing import List

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        if min(nums) < k:
            return -1
        return sum(i>k for i in set(nums))

if __name__ == "__main__":
    s = Solution()
    nums = [5,2,5,4,5]
    k = 2
    print(s.minOperations(nums, k))
