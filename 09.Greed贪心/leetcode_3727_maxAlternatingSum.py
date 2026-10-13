from typing import List

class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort(key = lambda x:abs(x), reverse = True)
        return sum(i*i for i in nums[:(n+1)//2]) - sum(i*i for i in nums[(n+1)//2:])

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.maxAlternatingSum(nums))
