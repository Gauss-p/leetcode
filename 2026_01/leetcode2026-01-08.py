from typing import List
from functools import cache

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        @cache
        def dfs(i, j): # 在nums1[i:]和nums2[j:]中能够取得的最大点积
            if i==n or j==m:
                return -float("inf")
            
            res = nums1[i]*nums2[j]+max(dfs(i+1, j+1), 0) # 选nums1[i]*nums[j]
            res1 = dfs(i+1, j) # 跳过索引i
            res2 = dfs(i, j+1) # 跳过索引j
            return max(res, res1, res2)
        return dfs(0, 0)

if __name__ == "__main__":
    s = Solution()
    nums1 = [2,1,-2,5]
    nums2 = [3,0,-6]
    print(s.maxDotProduct(nums1, nums2))
