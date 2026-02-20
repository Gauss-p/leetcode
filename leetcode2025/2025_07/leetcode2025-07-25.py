from typing import List

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        nums.sort()
        res, last = 0, float("inf")
        for i in nums:
            if i > 0 and i != last:
                res += i
                last = i
        return res if nums[-1]>=0 else nums[-1]

        # if max(nums) < 0:
        #     return max(nums)
        # nums = list(set(nums))
        # res = 0
        # for i in nums:
        #     if i>0:
        #         res += i
        # return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4,5]
    print(s.maxSum(nums))
