from typing import List
from collections import defaultdict
from bisect import *

class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        m = len(queries)
        nums = nums+nums
        pos = defaultdict(list)
        for i in range(len(nums)):
            pos[nums[i]].append(i)
        for i in range(m):
            queries.append(queries[i]+n)
        
        res = [10**18]*m
        for i in range(len(queries)):
            x = nums[queries[i]]
            indx = bisect_left(pos[x], queries[i])
            if indx > 0:
                res[i%m] = min(res[i%m], queries[i]-pos[x][indx-1])
            if indx+1 < len(pos[x]):
                res[i%m] = min(res[i%m], pos[x][indx+1]-queries[i])
        return [(-1 if i==n else i) for i in res]

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,1,4,1,3,2]
    queries = [0,3,5]
    print(s.solveQueries(nums, queries))
