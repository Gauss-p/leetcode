from typing import List
from collections import Counter, defaultdict

class Solution:
    def interactionCosts(self, n: int, edges: List[List[int]], group: List[int]) -> int:
        # 分析题目，我们需要对于每一个组，将该组中所有点对之间路径上的边数都加起来，最后将每一个组对应的和累加即可得到答案。如果直接按照这个思路进行模拟，我们需要先将所有点分类，然后对于每一个组循环其中所有可能的点对，求出两点间路径长度累加，但这样太过麻烦，不仅需要至多O(n*n)的时间遍历所有可能的点对，而且在计算点对的路径长度时还需要利用树上倍增法求出两个点的最近公共祖先，再用0到它们的距离进行计算，这又需要O(log(n))的时间，总共则需要O(n*n*log(n))，会超时
        # 因此我们重新分析题目，换一个计算方式。可以发现，说是要求每一个组中所有点对的两点间距离之和，但我们其实可以计算某一条边被统计的次数，将它们累加从而得到总和。这里可以用dfs的方式，首先以0为根节点建树，对于一个节点x，循环它的所有子节点y，我们需要统计边x->y被统计的总次数。如果它要被统计，那么一定需要在它的两侧均有所属组的编号相同的元素，即如果我们已经知道在同属第grp组的元素中，总共出现了tot[grp]次，且在以y为根节点的子树中总共出现了cnt[grp]次，那么可以知道，在边x->y的一侧有cnt[grp]个元素，另一侧有tot[grp]-cnt[grp]个元素，因此在同属于第grp组的点对中，路径经过边x->y的就有cnt[grp]*(tot[grp]-cnt[grp])个，也就是说它需要被统计这么多次
        # 根据上面的分析，我们需要先在整棵树的范围内统计出每一个grp值的出现次数，然后利用dfs递归的特性，统计以每一个节点为根节点的子树中，每一个grp值的出现次数，只有这样才能统计
        g = [[] for _ in range(n)]
        for a,b in edges:
            g[a].append(b)
            g[b].append(a)
        
        res = 0
        tot = Counter(group)
        def dfs(x, pa):
            nonlocal res
            cnt = defaultdict(int) # 以x为根节点的子树中，各个grp值出现次数
            cnt[group[x]] += 1
            for y in g[x]:
                if y == pa:
                    continue
                childCnt = dfs(y, x) # 获取以y为根节点的子树中，各个grp值出现次数
                for grp, grpCnt in childCnt.items():
                    res += grpCnt*(tot[grp]-grpCnt) # 利用公式统计边x->y被记录次数
                    cnt[grp] += grpCnt # 维护当前cnt
            return cnt
        dfs(0, -1) # 以0为根节点建树
        return res

if __name__ == "__main__":
    s = Solution()
    n = 3
    edges = [[0,1],[1,2]]
    group = [1,1,1]
    print(s.interactionCosts(n, edges, group))
