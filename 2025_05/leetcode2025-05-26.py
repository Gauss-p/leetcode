from typing import List
from collections import defaultdict

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        # 如果定义dfs(x)的返回值为：以x为根节点的子树中的各个颜色的最大颜色值，也就是对于每一种颜色，都从x出发，记录所有路径中该颜色出现的最大次数
        # 那么这样，如果我们需要计算以x为根节点的子树中各个颜色在路径中的最大出现次数(以下用cx来保存)，那么我们需要对于x的每一个子节点y，我们只需首先取出cy=dfs(y)，这样就求出了以y为根节点的子树中各个颜色在路径中的最大出现次数，对于cy中每一个颜色c和它在子树y中最大出现次数t，可以得到cx[c]=t，但如果颜色c正好和根节点x的颜色相同，那么cx[c]=t+1。又因为x有多个子节点，所以每一次需要求cx[c]的最大值，即：cx[c]=max(cy1[c], cy2[c], ..., cym[colors[x]]+1, ...)
        # 但是题目同时也要求我们判断树中是否有环路，因此我们需要用三色标记法来判断，用一个列表memo记录每个位置的状态，在该dfs函数中，我们用memo[x]=None表示节点x未访问过，用memo[x]=0表示节点x访问过但是还未计算出子树x的答案，用memo[x]=defaultdict(int)表示节点x已经访问过并计算出答案，且答案即为memo[x]
        # 那么如果在循环的过程中发现x的某个子节点y竟然满足memo[y]=0的条件，就说明这时候一定遇到了环路，那么我们可以选择直接用返沪额memo[y]的方式来为答案标记此处有环路。同时，在每一次进入函数时，如果当前节点x已经被访问过或已经计算出了答案，那么我们直接返回它即可，因为如果已经被访问过就说明遇到环路，如果计算出答案之后也不必再计算了，这里也相当于实现了记忆化搜索
        # 那么根据上面的叙述可以知道，dfs函数只有两种返回值，0或defaultdict(int)，如果是0，说明有环路，程序答案就应是-1，否则就是所有颜色中最大的出现次数

        n = len(colors)
        g = [[] for _ in range(n)] # 建图
        for a,b in edges:
            g[a].append(b)

        memo = [None]*n # 建立标识列表
        def dfs(x):
            if memo[x] is not None:
                # 如果memo[x]=0，即已访问但没计算答案，遇到环路
                # 如果memo[x]=defaultdict(int)，即访问过且计算了答案，直接返回答案即可
                return memo[x]
            memo[x] = 0
            ans = defaultdict(int)
            for y in g[x]:
                cy = dfs(y)
                if cy == 0: # 已访问但没计算答案，遇到环路
                    return cy
                for k, v in cy.items():
                    # 更新cx的答案
                    ans[k] = max(ans[k], v)
            ans[colors[x]] += 1 # 将当前颜色最大出现次数加1
            memo[x] = ans # 记忆化搜索
            return ans
        
        res = 0
        for i in range(n):
            # 从所有节点出发计算一次，答案就是每次算出来的颜色出现次数最大值
            ci = dfs(i)
            if not ci: # ci=0，说明出现环路
                return -1
            for v in ci.values():
                res = max(res, v)
        return res

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
