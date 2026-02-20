from typing import List

class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        for i in range(0, n):
            res = max(res, abs(nums[i]-nums[(i+1)%n]))
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,4]
    print(s.maxAdjacentDistance(nums))
