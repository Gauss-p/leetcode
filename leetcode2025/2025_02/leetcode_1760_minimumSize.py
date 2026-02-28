from typing import List

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        l, r = 0, max(nums)
        while l<r:
            mid = (l+r)//2
            if mid==0:
                return 1
            tmp = 0
            for i in nums:
                tmp += (i+mid-1)//mid-1
            if tmp>maxOperations:
                l = mid+1
            else:
                r = mid
        return l

if __name__ == "__main__":
    s = Solution()
    nums = [9]
    maxOperations = 2
    print(s.minimumSize(nums, maxOperations))
