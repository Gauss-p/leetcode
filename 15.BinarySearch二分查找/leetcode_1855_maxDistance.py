from typing import List
from bisect import *

class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        if nums1[-1] > nums2[0]:
            return 0
        stl = []
        n1, n2 = len(nums1), len(nums2)
        res = 0
        for i in range(n2):
            if i<n1:
                x1 = nums1[i]
                stl.insert(0, x1)
            x2 = nums2[i]
            # 必须加下面这个判断，因为算法中用-1代替没有值的情况，因此当二分一个小于nums1[-1]的数字时，就会找到-1的位置，出现多算的情况
            if nums2[i] < nums1[-1]:
                break
            res = max(res, bisect_right(stl, x2)-1+max(0, i+1-n1))
        return res

if __name__ == "__main__":
    s = Solution()
    nums1 = [55,30,5,4,2]
    nums2 = [100,20,10,10,5]
    print(s.maxDistance(nums1, nums2))
