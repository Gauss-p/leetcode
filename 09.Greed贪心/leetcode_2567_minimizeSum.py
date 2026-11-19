from typing import List

class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        nums.sort()
        return min(nums[-2]-nums[1], nums[-1]-nums[2], nums[-3]-nums[0])

if __name__ == "__main__":
    s = Solution()
    nums = [1,4,3]
    print(s.minimizeSum(nums))
