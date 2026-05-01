from typing import List

class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        # F(0) = 0*nums[0] + 1*nums[1] +...+ (n-2)*nums[n-2] + (n-1)*nums[n-1]
        # F(1) = 0*nums[n-1] + 1*nums[0] +...+ (n-2)*nums[n-3] + (n-1)*nums[n-2]
        #      = 1*nums[0] +...+ (n-2)*nums[n-3] + (n-1)*nums[n-2]
        #      = F(0) - (n-1)*nums[n-1] +(nums[0] +...+ nums[n-2])
        #      = F(0) - (n-1)*nums[n-1] + (sum(nums)-nums[n-1])
        #      = F(0) + sum(nums) - n*nums[n-1]

        # 即：F(1) = F(0)+sum(nums)-n*nums[n-1]
        # 因此可以倒过来循环nums，依次计算F(1), F(2)..., F(n-1)
        n = len(nums)
        tot = 0
        cur = 0
        for i in range(n):
            tot += nums[i]
            cur += nums[i]*i
        res = cur
        for i in range(n-1, 0, -1):
            cur += tot
            cur -= nums[i]*n
            res = max(res, cur)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [4,3,2,6]
    print(s.maxRotateFunction(nums))
