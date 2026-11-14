from typing import List

class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        preSum = [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+nums[i]
        
        res = 10**18
        for i in range(n-l+1):
            for length in range(l, r+1):
                if i+length <= n and preSum[i+length]-preSum[i]>0:
                    res = min(res, preSum[i+length]-preSum[i])
        return res if res<10**18 else -1

if __name__ == "__main__":
    s = Solution()
    nums = [3, -2, 1, 4]
    l = 2
    r = 3
    print(s.minimumSumSubarray(nums, l, r))
