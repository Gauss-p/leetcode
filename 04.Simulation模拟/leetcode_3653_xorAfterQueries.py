from typing import List

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        modNum = 1_000_000_007
        for l,r,k,v in queries:
            for i in range(l, r+1, k):
                nums[i] = (nums[i]*v)%modNum

        res = 0
        for i in nums:
            res ^= i
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,1]
    queries = [[0,2,1,4]]
    print(s.xorAfterQueries(nums, queries))
