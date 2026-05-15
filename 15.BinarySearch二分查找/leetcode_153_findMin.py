from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        # 以最后一个元素为分界点，如果nums[mid]>target，说明当前区间(l,r)相对于最小值位置整体偏左，需要调整左端点，否则说明当前区间相对最小值位置整体偏右，需要调整右端点
        n = len(nums)
        target = nums[-1]
        l, r = 0, n-1
        while l<=r:
            mid = (l+r)//2
            if nums[mid] > target:
                l = mid+1
            else:
                r = mid-1
        return nums[l]

if __name__ == "__main__":
    s = Solution()
    nums = [3,4,5,1,2]
    print(s.findMin(nums))
