from typing import List

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return max(nums)*len(nums) - sum(nums)

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,3]
    print(s.minMoves(nums))
