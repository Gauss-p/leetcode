from typing import List

class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        mxInc = 1
        cnt = 1
        for i in range(1, n):
            if nums[i-1] >= nums[i]:
                mxInc = max(mxInc, cnt)
                cnt = 0
            cnt += 1
        mxInc = max(mxInc, cnt)
        
        cnt = 1
        mxDec = 1
        for i in range(1, n):
            if nums[i-1] <= nums[i]:
                mxDec = max(mxDec, cnt)
                cnt = 0
            cnt += 1
        mxDec = max(mxDec, cnt)
        return max(mxInc, mxDec)

if __name__ == "__main__":
    s = Solution()
    nums = [1,4,3,3,2]
    print(s.longestMonotonicSubarray(nums))
