from typing import List
from collections import defaultdict
from heapq import *

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        n = len(changed)
        g = [[] for _ in range(26)]
        for i in range(n):
            g[ord(original[i])-ord('a')].append((ord(changed[i])-ord('a'), cost[i]))
        
        def generateDist(c):
            q = [(0,c)]
            dist = [float("inf")]*26
            dist[c] = 0
            visited = [0]*26
            while q:
                d, x = heappop(q)
                if visited[x] == 1:
                    continue
                visited[x] = 1
                for y,cost in g[x]:
                    cur = d+cost
                    if cur < dist[y]:
                        dist[y] = cur
                        heappush(q, (cur, y))
            return dist
        
        m = len(source)
        dic = defaultdict(list)
        res = 0
        for i in range(m):
            if source[i] != target[i]:
                indx1 = ord(source[i])-ord('a')
                indx2 = ord(target[i])-ord('a')
                if indx1 not in dic:
                    dic[indx1] = generateDist(indx1)
                if dic[indx1][indx2] == float("inf"):
                    return -1
                res += dic[indx1][indx2]
        return res

if __name__ == "__main__":
    s = Solution()
    source = "abcd"
    target = "acbe"
    original = ["a","b","c","c","e","d"]
    changed = ["b","c","b","e","b","e"]
    cost = [2,5,5,1,2,20]
    print(s.minimumCost(source, target, original, changed, cost))
