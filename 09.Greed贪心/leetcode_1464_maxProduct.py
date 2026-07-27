from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort()
        return (nums[-1]-1)*(nums[-2]-1)

if __name__ == "__main__":
    s = Solution()
    nums = [3,4,5,2]
    print(s.maxProduct(nums))
