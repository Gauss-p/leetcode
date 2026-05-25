from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [float("inf")]*n
        dp[0] = 0
        for i in range(0, n):
            for j in range(i+1, i+nums[i]+1):
                if j>=n:break
                dp[j] = dp[j] if dp[j]<dp[i]+1 else dp[i]+1
        return dp[n-1]

if __name__ == "__main__":
    s = Solution()
    nums = [2,3,1,1,4]
    print(s.jump(nums))
