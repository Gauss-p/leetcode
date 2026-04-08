from typing import List

class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        r = 0
        res = n-1
        for l in range(n):
            while r < n and nums[r] <= nums[l]*k:
                r += 1
            cur = n-(r-l)
            if cur < res:
                res = cur
        return res

        # n = len(nums)
        # nums.sort()
        # res = float("inf")
        # for i in range(n):
        #     res = min(res, i+n-1-(bisect_right(nums, nums[i]*k)-1))
        #     res = min(res, (n-1-i)+bisect_left(nums, (nums[i]+k-1)//k))
        # return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,5]
    k = 2
    print(s.minRemoval(nums, k))
