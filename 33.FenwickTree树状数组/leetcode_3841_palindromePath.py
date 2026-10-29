from typing import List

# 分析本题可知，两个点u,v之间的最短路径可以这样获得：找到从0开始到u的路径，以及从0开始到v的路径，再找到以0为根节点的情况下u和v的最近公共祖先x，两条路径相加再减去从0到x的路径即可得到。但本题需要判断这条路径上的所有字符重排后能否形成回文串，也就是需要知道这条路径上出现次数为奇数的字符个数，注意到如果用一个26位的二进制数字cnt来表示一条路径上各个字母出现次数是否位奇数，检验这条路径是否是一条回文路径只需判断cnt二进制中是否只有至多一个置位即可，即判断cnt&(cnt-1)是否为0即可。而且在这种定义下，一条路径对应的cnt也很好维护，对于新加入的字符c，若其在字母表中索引为i，那么只需要通过异或1<<i即可得到新的cnt值；
# 那么如果保存数组rootPathXor，其中rootPathXor[i]表示从0到节点i的唯一路径对应的cnt值，且对于u,v两点求出其最近公共祖先x，则u,v之间路径对应的cnt值即为rootPathXor[u]^rootPathXor[v]^(1<<ord(s[x]))，其中最后的异或是因为在进行前面两次异或之后，节点x的值被异或了两次结果没了，需要在加上一次。
# 如果题目不要求修改，那么到这里其实就可以结束了，但正由于要修改，因此需要用FenwickTree来维护修改过的元素，从而能够用上面的计算公式进行计算。如何维护？在LCA类中，最开始要通过dfs建树来获取每个节点的深度，如果对于一个节点x，在进入dfs函数的时候记录一个时间戳tin[x]，同时在退出dfs的时候记录一个时间戳tout[x]，那么最后计算出来时间戳位于(tin[x],tout[x])之间的所有节点都是以x为根的子树的节点。这样，由于修改节点x的值时只会影响它和以它为根的子树中的其他节点对应的rootPathXor中的值，恰好是编号位于(tin[x],tout[x])之间的节点，因此可以采用差分数组的思想，只需将tin[x]和tout[x]+1对应的位置分别更新即可。同时由于这里要求的是异或值，假设x对应的字符从a变成了b，也就意味着在cnt中它对应的值从1<<ord(a)变成了1<<ord(b)，如果对原有的值直接异或val=(1<<ord(a))^(1<<ord(b))，即可实现。因此可以在tin[x]和tout[x]+1对应的位置分别异或上val，在求前缀异或和的时候即可保证所有节点对应值的准确性。
# 综上所述，u,v之间的原始路径对应的异或值可以用lca建的树异或来求，但所有的更新信息都需要在FenwickTree中通过时间戳通过差分数组的方式来维护，因此为了得到最终的准确异或结果，不仅需要rootPathXor[u]^rootPathXor[v]^(1<<ord(s[x]))，还需要继续异或上fenwicktree对应数组的tin[u],tin[v]对应的前缀异或和，因为它们保存了从0到u这条路径上所有的更改和从0到v这条路径上的所有更改。

class LCA:
    # 用树上倍增法求最近公共祖先的大致思路如下：
    #   1.对于给出的两个节点x和y，如果深度不同，则先将两者提升到相同的高度
    #   2.将提升后的两个节点同步向上提升，直到最后一个使两个节点不同的高度
    #   3.最后任选一个节点，它的父节点就是最初x和y的最近公共祖先

    # 什么叫树上倍增法？上面思路中，如果用正常的暴力方法将一个节点提升到它的第k个祖先，那么时间复杂度是O(k)。注意到无论如何k都可以用多个二进制数字来表示，因此可以将其拆分成多个2的幂，分别进行提升。
    # 这时，如果提前将每个节点i的第2**j个祖先求出来，那么就可以在O(log(k))的时间复杂度内将一个节点提升到它的第k个祖先。同时，在第2步中将两节点同步向上提升，也可以利用已经处理出来的2的幂的祖先进行同步跳转。
    def __init__(self, edges, s):
        n = len(edges)+1
        g = [[] for _ in range(n)]
        for x,y in edges:
            g[x].append(y)
            g[y].append(x)
        
        m = n.bit_length()
        pa = [[-1]*m for _ in range(n)]

        tin = [0]*n
        tout = [0]*n
        clock = 0
        rootPathXor = [0]*n
        rootPathXor[0] = 1<<s[0]
        
        depth = [0]*n # 求出以0为根节点时，每个节点的深度
        def dfs(x, fa):
            pa[x][0] = fa
            nonlocal clock
            clock += 1
            tin[x] = clock
            for y in g[x]:
                if y == fa:
                    continue
                depth[y] = depth[x] + 1
                rootPathXor[y] = rootPathXor[x]^(1<<s[y])
                dfs(y, x)
            tout[x] = clock
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
        self.tin = tin
        self.tout = tout
        self.rootPathXor = rootPathXor
    
    def getKthAncestor(self, x, k):
        pos = 0
        while k: # 分解成不同的2的幂进行计算
            if k&1:
                x = self.pa[x][pos]
                if x < 0:
                    return -1
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

class FenwickTree:
    def __init__(self, n):
        self.tree = [0]*(n+1)

    def update(self, index: int, val: int) -> None:
        while index < len(self.tree):
            self.tree[index] ^= val
            index += (index&(-index)) # 往后更新

    def preSum(self, pos):
        # 按照预期的方式求前缀和
        ans = 0
        while pos >= 1:
            ans ^= self.tree[pos]
            pos -= (pos&(-pos))
        return ans

class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str, queries: list[str]) -> list[bool]:
        ns = [ord(c)-ord('a') for c in s]

        g = LCA(edges, ns)
        tin = g.tin # 进入dfs函数的时间
        tout = g.tout # 退出dfs函数的时间
        rootPathXor = g.rootPathXor # 从根节点到各个节点路径的原始异或值

        ft = FenwickTree(n)
        res = []

        for q in queries:
            op, x, y = q.split()
            x = int(x)
            if op == 'update':
                cur = ord(y)-ord('a')
                val = (1<<ns[x])^(1<<cur)
                ns[x] = cur
                ft.update(tin[x], val) # 将更改加入fenwicktree数组
                ft.update(tout[x]+1, val) # 采用差分数组的思想
            
            else:
                y = int(y)
                curlca = g.lca(x, y)
                # 注意还需异或上ft.preSum(tin[x])和ft.preSum(tin[y])，以同步两条路径上所有的更新
                totXor = rootPathXor[x]^rootPathXor[y]^ft.preSum(tin[x])^ft.preSum(tin[y])^(1<<ns[curlca])
                res.append(totXor & (totXor-1) == 0) # 统计答案
        return res

if __name__ == "__main__":
    sl = Solution()
    n = 3
    edges = [[0,1],[1,2]]
    s = "aac"
    queries = ["query 0 2","update 1 b","query 0 2"]
    print(sl.palindromePath(n, edges, s, queries))
