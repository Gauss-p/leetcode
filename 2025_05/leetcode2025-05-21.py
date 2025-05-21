from typing import List

class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        def check(lst):
            n = len(nums)
            sub = [0]*(n+1)
            sub[0] = nums[0]
            for i in range(1,n):
                sub[i] = nums[i] - nums[i-1]
            
            for l,r,v in lst:
                sub[l] -= v
                sub[r+1] += v
            
            tmp = 0
            for i in range(n):
                tmp += sub[i]
                if tmp > 0:
                    return False
            return True

        if not check(queries):
            return -1
        l, r = 0, len(queries)
        while l<r:
            mid = (l+r)//2
            if check(queries[:mid]):
                r = mid
            else:
                l = mid+1
        return l

if __name__ == "__main__":
    s = Solution()
    nums = [2,0,2]
    queries = [[0,2,1],[0,2,1],[1,1,3]]
    print(s.minZeroArray(nums, queries))
