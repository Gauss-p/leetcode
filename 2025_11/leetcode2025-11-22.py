from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        return sum(min(i%3, 3-i%3) for i in nums)

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4]
    print(s.minimumOperations(nums))
