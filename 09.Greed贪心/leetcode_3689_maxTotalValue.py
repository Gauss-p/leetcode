from typing import List

class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        return k*(max(nums)-min(nums))

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,2]
    k = 2
    print(s.maxTotalValue(nums, k))
