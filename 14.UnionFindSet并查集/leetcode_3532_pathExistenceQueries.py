from typing import List
from bisect import *

class UFS:
    def __init__(self, n):
        self.pa = list(range(n))
    
    def find(self, x):
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px < py:
            self.pa[py] = px
        else:
            self.pa[px] = py

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        ufs = UFS(n)
        for i in range(n):
            last = nums[i]-maxDiff
            lastIndx = bisect_left(nums, last)
            ufs.union(lastIndx, i)
        
        res = []
        for u,v in queries:
            res.append(ufs.find(u)==ufs.find(v))
        return res

if __name__ == "__main__":
    s = Solution()
    n = 2
    nums = [1,3]
    maxDiff = 1
    queries = [[0,0],[0,1]]
    print(s.pathExistenceQueries(n, nums, maxDiff, queries))
