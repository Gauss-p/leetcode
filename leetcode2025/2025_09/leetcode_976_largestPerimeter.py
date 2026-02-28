from typing import List

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        # 暴力，从大到小排序，以当前值为三角形最大边，那么最大的可能的剩下两条边就是当前值之后的两个值。因此，只要第i+1个和第i+2个值之和大于第i个值，就说明这三个数字可以构成三角形，又因为我们是从头到尾遍历的，因此只要发现可以构成一个三角形，这个三角形边长就一定是最大的，直接返回答案即可
        nums.sort(reverse = True)
        for i in range(len(nums)-2):
            if nums[i+1]+nums[i+2] > nums[i]:
                return nums[i+1]+nums[i+2]+nums[i]
        return 0

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,2]
    print(s.largestPerimeter(nums))
