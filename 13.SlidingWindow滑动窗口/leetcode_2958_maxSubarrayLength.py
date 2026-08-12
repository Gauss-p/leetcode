from typing import List
from collections import defaultdict

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0
        r = 0
        cnt = defaultdict(int)
        for l in range(n):
            while r<n and cnt[nums[r]]+1 <= k:
                cnt[nums[r]] += 1
                r += 1
            res = max(res, r-l)
            cnt[nums[l]] -= 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,1,2,3,1,2]
    k = 2
    print(s.maxSubarrayLength(nums, k))
