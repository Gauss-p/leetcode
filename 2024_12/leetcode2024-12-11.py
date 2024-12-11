from typing import List

class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        mn,mx,n = 0,0,len(nums)
        for i in range(n):
            if nums[i] == 1:
                mn = i
            if nums[i] == n:
                mx = i
        res = mn+(n-mx-1)
        if mx < mn:
            res -= 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,4,1,3]
    print(s.semiOrderedPermutation(nums))
