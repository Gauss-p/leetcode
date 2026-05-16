from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        # 对于一个区间[l, r]，取它的中点mid = (l+r)//2，那么此时nums[mid]和nums[r]的大小关系就有三种可能，并且分别对应三种不同的最小值位置情况：
        # 1.nums[mid]>nums[r]，这说明在nums的左右两端递增数组中，mid位于左侧递增数组，也就意味着最小值位置一定位于[mid+1, r]区间中，因此此时需要将l变成mid+1
        # 2.nums[mid]<nums[r]，说明此时mid位于右侧递增数组中，因此最小值位置一定位于[l,mid]区间中，需要将r变成mid
        # 3.nums[mid]=nums[r]，此时无法判断最小值位置在哪个区间中，因此可以选择将右端点左移一个位置缩小区间。这样做之所以不会出错是因为：1、如果最小值位置位于r的左侧，那么当前操作不会跳过最小值位置；2、如果最小值位置位于r的位置，那么由于已经保证在r的左侧还有一个位置mid能够满足nums[mid]=nums[r]，因此就算跳过了r，左边还有一个最小值，找到左边那个最小值即可
        n = len(nums)
        l, r = 0, n-1
        while l<r:
            mid = (l+r)//2
            if nums[mid] > nums[r]:
                l = mid+1
            elif nums[mid] < nums[r]:
                r = mid
            else:
                r -= 1
        return nums[l]

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,5]
    print(s.findMin(nums))
