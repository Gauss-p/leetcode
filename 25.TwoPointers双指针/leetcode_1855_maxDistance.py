from typing import List

class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        i1 = 0
        res = 0
        for i2 in range(n2):
            while i1<n1 and nums1[i1] > nums2[i2]:
                i1 += 1
            if i1 == n1:
                break
            if i1 <= i2:
                res = max(res, i2-i1)
        return res

if __name__ == "__main__":
    s = Solution()
    nums1, nums2 = [55,30,5,4,2], [100,20,10,10,5]
    print(s.maxDistance(nums1, nums2))
