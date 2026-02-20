from typing import List
from collections import Counter

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c1, c2 = Counter(nums1), Counter(nums2)
        res = []
        for k in c1:
            if k in c2:
                res += [k]*min(c1[k], c2[k])
        return res

if __name__ == "__main__":
    s = Solution()
    nums1,nums2 = [2,2],[1,2,2,1]
    print(s.intersect(nums1, nums2))
