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
        self.pa[py] = px

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        # 求出以k为根节点的子树中节点总个数，这些节点都是可疑节点，之后求出k所在连通块的大小，如果两个数字相等，说明有一个连通块中的所有节点都是可疑节点，那么就将它们全部删除，否则说明有某个好节点调用了可疑节点，这种情况下就不能删除任何节点，因为只要删除就会让剩余的方法无法连续地调用
        g = [[] for _ in range(n)]
        ufs = UFS(n)
        for a,b in invocations:
            ufs.union(a, b)
            g[a].append(b)
        
        visited = [0]*n
        def dfs(x):
            visited[x] = 1
            for y in g[x]:
                if visited[y]:
                    continue
                dfs(y)
        dfs(k)
        bad = sum(visited)
        tot = 0
        others = []
        for i in range(n):
            if ufs.find(i) == ufs.find(k):
                tot += 1
            else:
                others.append(i)
        
        if bad < tot:
            return list(range(n))
        
        return others

if __name__ == "__main__":
    s = Solution()
    n, k = 4, 1
    invocations = [[1,2],[0,1],[3,2]]
    print(s.remainingMethods(n, k, invocations))
