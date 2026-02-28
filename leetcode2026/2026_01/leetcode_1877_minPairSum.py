from typing import List

class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        for i in range(len(nums)//2):
            cur = nums[i]+nums[-i-1]
            if cur > res:
                res = cur
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,5,2,3]
    print(s.minPairSum(nums))
