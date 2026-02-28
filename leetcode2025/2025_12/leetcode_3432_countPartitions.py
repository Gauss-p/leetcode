from typing import List

class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        n = len(nums)
        tot = sum(nums)
        preSum = 0
        res = 0
        for i in range(n-1):
            preSum += nums[i]
            if (preSum-(tot-preSum))%2 == 0:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [10,10,3,7,6]
    print(s.countPartitions(nums))
