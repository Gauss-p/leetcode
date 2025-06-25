from typing import List
from bisect import *

class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        # 考虑二分查找，我们需要一个check函数，用来判断二分产生出来的mid是否符合要求，主要思路就是看nums1和nums2中是否能够产生出k个小于mid的乘积
        # 我们可以借助题目中nums1和nums2已经排序好的便利来计算小于mid的乘积个数。在nums1中如果有一个数字x，分成三种情况，如果x>0，那么我们就需要在nums2中寻找一个最大的值，使其能够满足y*x<mid，如果x=0，那么就需要根据mid是否大于等于0来判断，而如果x<0，那么我们就需要在nums2中寻找一个最小的值，使其能够满足y*x<mid。这里就可以使用二分查找了
        def check(x):
            cnt = 0
            for i in nums1:
                if i>0:
                    j = x//i
                    cnt += bisect_right(nums2, j) # 查找到最右边的位置y，使其能够满足nums2[y]*i<x
                elif i==0:
                    if x>=0:
                        cnt += len(nums2)
                else:
                    j = -(x//(-i))
                    cnt += len(nums2)-bisect_left(nums2, j) # 查找到最左边的位置y，使其能够满足nums2[y]*i<x，又因为如果i<0，那么按从小到大的顺序排列乘积时，nums2其实是从后到前排列的，因此需要用总长度减
            return cnt

        l, r = -1_000_000_000_0, 1_000_000_000_0
        while l<r:
            mid = (l+r)//2
            cur = check(mid)
            if cur<k:
                l = mid+1
            else:
                r = mid
        return l

if __name__ == "__main__":
    s = Solution()
    nums1 = [2,5]
    nums2 = [3,4]
    k = 2
    print(s.kthSmallestProduct(nums1, nums2, k))
