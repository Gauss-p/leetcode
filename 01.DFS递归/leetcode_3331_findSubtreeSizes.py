from typing import List

class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        g = [[] for _ in range(n)]
        for i in range(1, n):
            g[parent[i]].append(i)

        ancestor = [-1]*26
        def dfs(x):
            cur = ord(s[x])-ord('a')
            if ancestor[cur] != -1:
                parent[x] = ancestor[cur]
            last = ancestor[cur]
            ancestor[cur] = x

            for y in g[x]:
                dfs(y)
            ancestor[cur] = last
        dfs(0)

        ng = [[] for _ in range(n)]
        for i in range(1, n):
            ng[parent[i]].append(i)

        res = [0]*n
        def calcSize(x):
            res[x] = 1
            for y in ng[x]:
                res[x] += calcSize(y)
            return res[x]
        calcSize(0)
        return res

if __name__ == "__main__":
    sl = Solution()
    parent = [-1, 0, 0, 1, 1, 1]
    s = "abaabc"
    print(sl.findSubtreeSizes(parent, s))
