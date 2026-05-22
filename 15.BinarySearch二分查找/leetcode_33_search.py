from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l<=r:
            mid = (l+r)//2
            if nums[mid] <= nums[-1]:
                r = mid-1
            else:
                l = mid+1
        
        indx = r
        l, r = 0, len(nums)-1
        if target <= nums[-1]:
            l = indx+1
        else:
            r = indx
        while l<=r:
            mid = (l+r)//2
            if nums[mid] < target:
                l = mid+1
            else:
                r = mid-1
                
        return l if l<len(nums) and nums[l]==target else -1

if __name__ == "__main__":
    s = Solution()
    nums = [4,5,6,7,0,1,2]
    target = 0
    print(s.search(nums, target))
