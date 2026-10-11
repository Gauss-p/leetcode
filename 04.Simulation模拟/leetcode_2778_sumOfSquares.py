from typing import List

class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        return sum(v*v for i,v in enumerate(nums) if len(nums)%(i+1)==0)

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4]
    print(s.sumOfSquares(nums))
