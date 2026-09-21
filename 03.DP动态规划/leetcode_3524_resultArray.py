from typing import List

class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        dp = [[0]*k for _ in range(n+1)]
        res = [0]*k
        for i in range(n):
            v = nums[i]%k
            dp[i+1][v%k] = 1
            for j in range(k):
                dp[i+1][(j*v)%k] += dp[i][j]
            for j in range(k):
                res[j] += dp[i+1][j]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4,5]
    k = 3
    print(s.resultArray(nums, k))
