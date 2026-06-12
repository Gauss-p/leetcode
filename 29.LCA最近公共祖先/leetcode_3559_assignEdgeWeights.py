from typing import List

# 由本题的第I题可以知道，当两点之间距离是d时，总的权重分配方式数量就是2**(d-1)，因此问题就变成了：求出两点间距离。
# 如果知道了从一个点开始到达树中所有点的距离(记从这个点开始到节点i的距离为d[i])，那么为了求两个点x和y的距离，就应当先求出来x和y的最近公共祖先anc，然后距离就是d[x]+d[y]-2*d[anc].

# 用树上倍增法求最近公共祖先的大致思路如下：
#   1.对于给出的两个节点x和y，如果深度不同，则先将两者提升到相同的高度
#   2.将提升后的两个节点同步向上提升，直到最后一个使两个节点不同的高度
#   3.最后任选一个节点，它的父节点就是最初x和y的最近公共祖先

# 什么叫树上倍增法？上面思路中，如果用正常的暴力方法将一个节点提升到它的第k个祖先，那么时间复杂度是O(k)。注意到无论如何k都可以用多个二进制数字来表示，因此可以将其拆分成多个2的幂，分别进行提升。
# 这时，如果提前将每个节点i的第2**j个祖先求出来，那么就可以在O(log(k))的时间复杂度内将一个节点提升到它的第k个祖先。同时，在第2步中将两节点同步向上提升，也可以利用已经处理出来的2的幂的祖先进行同步跳转。

class LCA:
    def __init__(self, edges):
        n = len(edges)+1
        g = [[] for _ in range(n)]
        for x,y in edges:
            g[x-1].append(y-1)
            g[y-1].append(x-1)
        
        m = n.bit_length()
        pa = [[-1]*m for _ in range(n)]
        
        depth = [0]*n # 求出以0为根节点时，每个节点的深度
        def dfs(x, fa):
            pa[x][0] = fa
            for y in g[x]:
                if y == fa:
                    continue
                depth[y] = depth[x] + 1
                dfs(y, x)
        dfs(0, -1)

        for j in range(1, m):
            for i in range(n):
                # 节点i的第2**j个祖先可以拆成两部分：
                #   1.节点i的第2**(j-1)个祖先(这个祖先记为a)；
                #   2.节点a的第2**(j-1)个祖先；
                # 因此可以得出：pa[i][j] = pa[pa[i][j-1]][j-1]
                pa[i][j] = pa[pa[i][j-1]][j-1]
        
        self.pa = pa
        self.depth = depth
    
    def getKthAncestor(self, x, k):
        pos = 0
        while k: # 分解成不同的2的幂进行计算
            if k&1:
                x = self.pa[x][pos]
            k >>= 1
            pos += 1
        return x
    
    def lca(self, x, y):
        if self.depth[x] > self.depth[y]:
            x, y = y, x
        
        diff = self.depth[y]-self.depth[x]
        y = self.getKthAncestor(y, diff) # 提升到同一高度
        if y == x:
            return x
        
        for i in range(len(self.pa[x])-1, -1, -1):
            px, py = self.pa[x][i], self.pa[y][i]
            if px != py: # 只要跳转后仍不相等，就跳转
                x, y = px, py
        # 上述循环保证在循环结束时一定有：x!=y且pa[x][0]=pa[y][0]，因此pa[x][0]一定是原x和y的最近公共祖先
        return self.pa[x][0]


class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        modNum = 1_000_000_007
        calc = LCA(edges)
        res = []
        for x,y in queries:
            x -= 1
            y -= 1
            # 计算两点间距离
            cur = calc.depth[x]+calc.depth[y]-2*calc.depth[calc.lca(x, y)]
            if cur > 0:
                res.append(pow(2, cur-1, modNum))
            else:
                res.append(0)
        return res

if __name__ == "__main__":
    s = Solution()
    edges = [[1,2]]
    queries = [[1,1],[1,2]]
    print(s.assignEdgeWeights(edges, queries))
