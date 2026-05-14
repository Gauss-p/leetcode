from typing import List

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        myMin = lambda x,y : x if x<y else y
        def calc(orList):
            tmp = 0
            for i in range(32):
                if orList[i]>=1:
                    tmp += (1<<i)
            return tmp
        orList = [0]*32
        n = len(nums)
        l,r = 0,0
        res = float("inf")
        for r in range(n):
            orList = [orList[i]+((nums[r]>>i)&1) for i in range(32)]
            while l<=r and calc(orList)>=k:
                res = myMin(res, r-l+1)
                orList = [orList[i]-((nums[l]>>i)&1) for i in range(32)]
                l += 1
        return -1 if res==float("inf") else res

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,8]
    k = 10
    print(s.minimumSubarrayLength(nums, k))
