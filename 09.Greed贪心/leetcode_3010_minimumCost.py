from typing import List

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        res = nums[0]
        nums = sorted(nums[1:])
        return res+nums[0]+nums[1]

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,12]
    print(s.minimumCost(nums))
