from typing import List

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
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        ufs = UFS(n)
        for a,b,d in roads:
            a -= 1
            b -= 1
            ufs.union(a, b)
        
        target = ufs.find(0)
        dic = set()
        for i in range(n):
            if ufs.find(i) == target:
                dic.add(i)
        
        res = 10**18
        for a,b,d in roads:
            a -= 1
            b -= 1
            if a in dic and b in dic:
                res = min(res, d)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 4
    roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
    print(s.minScore(n, roads))
