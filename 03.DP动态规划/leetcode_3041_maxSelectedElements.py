from typing import List
from collections import defaultdict

class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        # dp[x]表示以数字x为结尾的最大连续元素数目
        nums.sort()
        dp = defaultdict(int)
        for x in nums:
            dp[x+1] = max(dp[x+1], dp[x]+1)
            dp[x] = max(dp[x], dp[x-1]+1)
        return max(dp.values())

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,5,1,1]
    print(s.maxSelectedElements(nums))
