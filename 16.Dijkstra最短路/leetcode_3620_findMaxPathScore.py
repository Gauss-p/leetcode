from typing import List
from heapq import *

class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        # 取一个最小边成本，在所有成本大于等于这个值，且两端点都在线的边中，用Dijkstra算法查找从0到n-1的最小路径总花费是否超过k，如果超过，说明当前设定的最小边成本过大，否则说明它过小
        n = len(online)
        l, r = 10**18, 0
        g = [[] for _ in range(n)]
        for u,v,cost in edges:
            l = min(l, cost)
            r = max(r, cost)
            if online[u] and online[v]:
                g[u].append((v, cost))
        
        def check(mid):
            q = [(0,0)]
            dist = [10**18]*n
            dist[0] = 0
            visited = [0]*n
            while q:
                d,x = heappop(q)
                if visited[x]:
                    continue
                visited[x] = 1
                for y,c in g[x]:
                    if c < mid:
                        continue
                    if d+c < dist[y]:
                        dist[y] = d+c
                        heappush(q, (dist[y], y))
            return dist[n-1] <= k

        # 如果在所有边中都找不到一条满足条件的路径，那么直接返回-1即可
        if not check(l):
            return -1
        
        while l<=r:
            mid = (l+r)//2
            if check(mid):
                l = mid+1
            else:
                r = mid-1
        return r

if __name__ == "__main__":
    s = Solution()
    edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]]
    online = [True,True,True,True]
    k = 10
    print(s.findMaxPathScore(edges, online, k))
