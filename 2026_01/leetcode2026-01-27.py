from typing import List
from heapq import *

class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for u,v,w in edges:
            g[u].append((v, w))
            g[v].append((u, w*2))
        
        dist = [float("inf")]*n
        dist[0] = 0
        q = [(0,0)]
        while q:
            d, x = heappop(q)
            for y,w in g[x]:
                cur = d+w
                if cur < dist[y]:
                    dist[y] = cur
                    heappush(q, (cur, y))
        return dist[n-1] if dist[n-1] != float("inf") else -1

if __name__ == "__main__":
    s = Solution()
    n = 4
    edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
    print(s.minCost(n, edges))
