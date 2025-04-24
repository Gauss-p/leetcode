from typing import List
from collections import defaultdict

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        m = len(set(nums))
        cnt = defaultdict(int)
        r = 0
        res = 0
        for l in range(n):
            while r<n and len(cnt)<m:
                cnt[nums[r]] += 1
                r += 1
            if len(cnt) == m:
                res += (n-r+1)
            cnt[nums[l]] -= 1
            if cnt[nums[l]] == 0:
                cnt.pop(nums[l])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,1,1,2]
    print(s.countCompleteSubarrays(nums))
