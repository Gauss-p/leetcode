from typing import List

class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        sub = [0]*(n+1)
        sub[0] = nums[0]
        for i in range(1,n):
            sub[i] = nums[i] - nums[i-1]
        
        for l,r in queries:
            sub[l] -= 1
            sub[r+1] += 1
        
        tmp = 0
        for i in range(n):
            tmp += sub[i]
            if tmp > 0:
                return False
        return True

if __name__ == "__main__":
    s = Solution()
    nums = [1,0,1]
    queries = [[0,2]]
    print(s.isZeroArray(nums, queries))
