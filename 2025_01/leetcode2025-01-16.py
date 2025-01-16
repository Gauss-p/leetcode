from typing import List

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        for l in range(1,n+1):
            for i in range(n-l+1):
                cur_or = 0
                for j in range(i, i+l):
                    cur_or = cur_or | nums[j]
                if cur_or >= k:
                    return l
        return -1

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    k = 2
    print(s.minimumSubarrayLength(nums, k))
