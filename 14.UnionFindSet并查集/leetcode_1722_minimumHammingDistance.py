from typing import List
from collections import defaultdict

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
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        ufs = UFS(n)
        for u,v in allowedSwaps:
            ufs.union(u, v)
        
        groups = defaultdict(list)
        for i in range(n):
            groups[ufs.find(i)].append(i)
            
        def calc(pos):
            cnt = defaultdict(int)
            for i in pos:
                cnt[source[i]] += 1
                cnt[target[i]] -= 1
            ans = 0
            for v in cnt.values():
                ans += abs(v)
            return ans//2
        
        res = 0
        for pos in groups.values():
            res += calc(pos)
        return res

if __name__ == "__main__":
    s = Solution()
    source = [1,2,3,4]
    target = [2,1,4,5]
    allowedSwaps = [[0,1],[2,3]]
    print(s.minimumHammingDistance(source, target, allowedSwaps))
