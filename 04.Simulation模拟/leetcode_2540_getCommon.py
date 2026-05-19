from typing import List

class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        res = set(nums1).intersection(set(nums2))
        return min(res) if len(res) else -1

if __name__ == "__main__":
    s = Solution()
    nums1, nums2 = [1,2,3],[2,4]
    print(s.getCommon(nums1, nums2))
