from typing import List

class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        n = len(edges)+1
        g = [[] for _ in range(n+1)]
        for x,y in edges:
            g[x].append(y)
            g[y].append(x)
        
        def dfs(x, pa):
            ans = 0
            for y in g[x]:
                if y == pa:
                    continue
                nxt = 1+dfs(y, x)
                if nxt > ans:
                    ans = nxt
            return ans
        
        length = dfs(1, -1)
        return pow(2, length-1, 1_000_000_007)

if __name__ == "__main__":
    s = Solution()
    edges = [[1,2]]
    print(s.assignEdgeWeights(edges))
