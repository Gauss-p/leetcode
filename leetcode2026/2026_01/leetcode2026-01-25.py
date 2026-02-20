from typing import List

class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        res = float("inf")
        for i in range(n-k+1):
            cur = nums[i+k-1]-nums[i]
            if cur < res:
                res = cur
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [90]
    k = 1
    print(s.minimumDifference(nums, k))
