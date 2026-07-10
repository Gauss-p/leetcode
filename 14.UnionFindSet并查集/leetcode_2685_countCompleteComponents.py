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
        if px<py:
            self.pa[py] = px
        else:
            self.pa[px] = py

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        ufs = UFS(n)
        for a,b in edges:
            ufs.union(a, b)
        
        groups = defaultdict(int)
        cnt = defaultdict(int)
        for i in range(n):
            groups[ufs.find(i)] += 1
        for a,b in edges:
            cnt[ufs.find(a)] += 1

        res = 0
        for i in groups.keys():
            if cnt[i] == groups[i]*(groups[i]-1)//2:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    n = 6
    edges = [[0,1],[0,2],[1,2],[3,4]]
    print(s.countCompleteComponents(n, edges))
