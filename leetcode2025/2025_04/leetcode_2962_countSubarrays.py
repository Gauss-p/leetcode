from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mx = max(nums)
        res = 0
        r = 0
        cnt = 0
        for l in range(n):
            while cnt<k and r<n:
                cnt += (nums[r]==mx)
                r += 1
            if cnt>=k:
                res += n-r+1
            cnt -= (nums[l]==mx)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,2,3,3]
    k = 2
    print(s.countSubarrays(nums, k))
