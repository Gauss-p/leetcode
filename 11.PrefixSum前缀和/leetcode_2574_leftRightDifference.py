from typing import List

class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        lSum = [0]*n
        rSum = [0]*n
        for i in range(n-1):
            lSum[i+1] = lSum[i]+nums[i]
            rSum[n-i-2] = rSum[n-i-1]+nums[n-i-1]
        return [abs(lSum[i]-rSum[i]) for i in range(n)]

if __name__ == "__main__":
    s = Solution()
    nums = [10,4,8,3]
    print(s.leftRightDifference(nums))
