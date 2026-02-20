from typing import List
from collections import defaultdict,deque

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        # ===================================================================================
        # 以下为拓扑排序
        # ===================================================================================

        # 如果我们将每一个节点看作一条路径的终点，即我们以x为终点定义状态，那么可以得到如下的定义方式：
        # 定义f[x][i]表示终点为x的路径中，颜色i的最大出现次数，需要注意的是，这里终点不计算入颜色出现次数中
        # 对于每一个节点x，如果要让这条路径继续下去，就需要将它的各个子节点y接到这条路径的后边，也就是f[y]需要从f[x]进行转移。如果当前循环到节点x，那么首先我们需要将x对应的颜色出现次数先加上1，接下来，对于f[x]中每一个颜色i，又因为f[y]是不计算y对应的颜色的，因此所有f[y][i]都可以从f[x][i]转移，也就是在当前情况下，f[y][i]=f[x][i]，但是我们需要求最大出现次数，因此每次都需要f[y][i] = max(f[y][i], f[x][i])来更新
        # 那么因为如果要计算每一个节点的完整答案，就需要将它的所有转移来源都计算一次，所以我们需要用入度是否为0的方法来判断是否计算完了一个节点的所有父节点。在最开始，我们利用给出的边计算出每一个节点的入度，之后将所有入度为0的节点加入到一个队列中，循环这个队列，假设当前循环到的节点是x，那么对于它的每一个子节点y，我们都需要更新y的答案，而如何判断y是否计算完所有的父节点了呢？我们只需在每次更新完y的答案后将y的入度减1，最后判断y的入度是否变为0了，如果它变成0，就说明它从所有父节点都转移了一次，那么这时我们就可以将y加入队列，等候下一轮的计算了
        # 为了判断环路，因为如果有环就一定循环不到所有节点，所以我们可以用visited计数，每次遇到一个新的节点就将visited加1，最后判断，如果visited的数值等于节点总数，就说明这个图中没有环，返回答案即可，否则返回-1
        # 这里的答案在每次循环到一个新的x节点时就更新一次，因为如果更新y是没有意义的，这时它还没有算完
        n = len(colors)
        g = [[] for _ in range(n)] # 建图
        deg = [0]*n # 计算入度
        for a,b in edges:
            g[a].append(b)
            deg[b] += 1

        q = deque() # 首次加入入度为0的所有节点
        for i in range(n):
            if deg[i] == 0:
                q.append(i)

        memo = [defaultdict(int) for _ in range(n)]
        visited = 0
        res = 0
        while q:
            x = q.popleft() # 取出当前节点
            visited += 1 # 更新已访问的节点数量
            memo[x][colors[x]] += 1 # 对当前节点的颜色出现次数进行更新
            res = max(res, memo[x][colors[x]]) # 记录答案

            for y in g[x]:
                for c, t in memo[x].items():
                    memo[y][c] = max(memo[y][c], t)
                deg[y] -= 1
                if deg[y] == 0: # 准备下一次计算
                    q.append(y)

        if visited != n: # 有环路
            return -1
        return res


        # ===================================================================================
        # 以下为三色标记法判断环路+DFS+记忆化搜索，通过
        # ===================================================================================

        # 如果定义dfs(x)的返回值为：以x为根节点的子树中的各个颜色的最大颜色值，也就是对于每一种颜色，都从x出发，记录所有路径中该颜色出现的最大次数
        # 那么这样，如果我们需要计算以x为根节点的子树中各个颜色在路径中的最大出现次数(以下用cx来保存)，那么我们需要对于x的每一个子节点y，我们只需首先取出cy=dfs(y)，这样就求出了以y为根节点的子树中各个颜色在路径中的最大出现次数，对于cy中每一个颜色c和它在子树y中最大出现次数t，可以得到cx[c]=t，但如果颜色c正好和根节点x的颜色相同，那么cx[c]=t+1。又因为x有多个子节点，所以每一次需要求cx[c]的最大值，即：cx[c]=max(cy1[c], cy2[c], ..., cym[colors[x]]+1, ...)
        # 但是题目同时也要求我们判断树中是否有环路，因此我们需要用三色标记法来判断，用一个列表memo记录每个位置的状态，在该dfs函数中，我们用memo[x]=None表示节点x未访问过，用memo[x]=0表示节点x访问过但是还未计算出子树x的答案，用memo[x]=defaultdict(int)表示节点x已经访问过并计算出答案，且答案即为memo[x]
        # 那么如果在循环的过程中发现x的某个子节点y竟然满足memo[y]=0的条件，就说明这时候一定遇到了环路，那么我们可以选择直接用返沪额memo[y]的方式来为答案标记此处有环路。同时，在每一次进入函数时，如果当前节点x已经被访问过或已经计算出了答案，那么我们直接返回它即可，因为如果已经被访问过就说明遇到环路，如果计算出答案之后也不必再计算了，这里也相当于实现了记忆化搜索
        # 那么根据上面的叙述可以知道，dfs函数只有两种返回值，0或defaultdict(int)，如果是0，说明有环路，程序答案就应是-1，否则就是所有颜色中最大的出现次数

        # n = len(colors)
        # g = [[] for _ in range(n)] # 建图
        # for a,b in edges:
        #     g[a].append(b)

        # memo = [None]*n # 建立标识列表
        # def dfs(x):
        #     if memo[x] is not None:
        #         # 如果memo[x]=0，即已访问但没计算答案，遇到环路
        #         # 如果memo[x]=defaultdict(int)，即访问过且计算了答案，直接返回答案即可
        #         return memo[x]
        #     memo[x] = 0
        #     ans = defaultdict(int)
        #     for y in g[x]:
        #         cy = dfs(y)
        #         if cy == 0: # 已访问但没计算答案，遇到环路
        #             return cy
        #         for k, v in cy.items():
        #             # 更新cx的答案
        #             ans[k] = max(ans[k], v)
        #     ans[colors[x]] += 1 # 将当前颜色最大出现次数加1
        #     memo[x] = ans # 记忆化搜索
        #     return ans

        # res = 0
        # for i in range(n):
        #     # 从所有节点出发计算一次，答案就是每次算出来的颜色出现次数最大值
        #     ci = dfs(i)
        #     if not ci: # ci=0，说明出现环路
        #         return -1
        #     for v in ci.values():
        #         res = max(res, v)
        # return res

        # ===================================================================================
        # 以下为DFS暴力解法，超时
        # ===================================================================================

        # n = len(colors)
        # g = [[] for _ in range(n)]
        # for a,b in edges:
        #     g[a].append(b)

        # visited = [0]*n
        # @cache
        # def is_circle(x):
        #     if visited[x]:
        #         return True
        #     visited[x] = 1
        #     ans = False
        #     for y in g[x]:
        #         ans |= is_circle(y)
        #     visited[x] = 0
        #     return ans

        # if is_circle(0):
        #     return -1

        # c = [0]*26
        # def dfs(x):
        #     c[ord(colors[x])-ord('a')] += 1
        #     if len(g[x]) == 0:
        #         ans = max(c)
        #         c[ord(colors[x])-ord('a')] -= 1
        #         return ans

        #     ans = 0
        #     for y in g[x]:
        #         ans = max(ans, dfs(y))
        #     c[ord(colors[x])-ord('a')] -= 1
        #     return ans

        # res = 0
        # for i in range(n):
        #     res = max(res, dfs(i))
        #     c = [0]*26
        # return res

if __name__ == "__main__":
    s = Solution()
    colors = "abaca"
    edges = [[0,1],[0,2],[2,3],[3,4]]
    print(s.largestPathValue(colors, edges))
