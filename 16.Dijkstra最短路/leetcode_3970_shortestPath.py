from typing import List
from heapq import *

class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        g = [[] for _ in range(n)]
        for u,v,w in edges:
            g[u].append((v,w))

        q = [(0, 0, labels[0], 1)]
        dist = [[10**18]*(k+1) for _ in range(n)]
        dist[0][1] = 0
        visited = [[0]*(k+1) for _ in range(n)]
        while q:
            d, x, c, l = heappop(q)
            if visited[x][l]:
                continue
            visited[x][l] = 1
            for y,w in g[x]:
                nl = 1
                if labels[y] == c:
                    nl += l
                if nl > k:
                    continue
                if d+w < dist[y][nl]:
                    dist[y][nl] = d+w
                    heappush(q, (dist[y][nl], y, labels[y], nl))
        res = min(dist[n-1])
        return res if res < 10**18 else -1

if __name__ == "__main__":
    s = Solution()
    n = 3
    edges = [[0,1,1],[1,2,1],[0,2,3]]
    labels = "aab"
    k = 1
    print(s.shortestPath(n, edges, labels, k))
