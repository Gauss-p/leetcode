from typing import List

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        pre, aft = [0]*(n+1), [0]*(n+1)
        for i in range(n):
            pre[i+1] = max(pre[i], nums[i])
            aft[n-i-1] = max(aft[n-i], nums[n-i-1])
        res = 0
        for i in range(n):
            res = max(res, (pre[i]-nums[i])*aft[i+1])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [12,6,1,2,7]
    print(s.maximumTripletValue(nums))
