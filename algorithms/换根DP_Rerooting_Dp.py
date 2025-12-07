# https://leetcode.cn/problems/maximum-subgraph-score-in-a-tree/
# 3772.子图的最大得分

from typing import List

class Solution:
    def maxSubgraphScore(self, n: int, edges: List[List[int]], good: List[int]) -> List[int]:
        # 分析题目，可以发现节点i对应的最大得分就是：将所有好节点的值赋为1，将所有坏节点的值赋为-1，此时，以i为原点向外扩散的过程中，每个方向上均计算出从i开始的路径上节点的值之和的最大值，最后将所有方向上的最大值加起来即可。因此可以想到DFS的方法，从每一个节点出发，寻找从它开始所有方向的最大和即可。在寻找最大和的时候，需要在“递归”中“归”的时候进行计算，可以发现，dfs(x, pa)=sum(max(dfs(y, x),0) for y in g[x] if y!=pa)+good[x]，也就是在每个方向上都求出最大和，但如果某个方向上的最大和都是负数，我们便可以选择不走该方向，加0即可，需要注意的是，最后还需要加上根节点的值
        # 用上面的dfs函数，我们可以轻松计算所有答案，但这需要以每个节点为根节点都开一次dfs函数，总共就需要O(n**2)的时间，这时候就需要用到“换根DP”，顾名思义，就是将一个数的根换成树中的另一个节点，重新计算所有可能的贡献值，在这道题目中，如果我们先用一次上面的dfs，就可以计算出：以0为根节点时，以各个节点为子树对应的最大得分，注意，我们真正需要求的是「以每一个节点为根节点时，整个树的最大得分」，和这里求出的并不相同，这里只是先由「0为根节点」决定出层序关系，最后对每一个更小的子树进行计算的
        # 为了实现上面所说的换根，我们需要回答以下问题：已经知道一个以x为根节点的最大得分，一个以y为根节点的最大得分，且y为x的下一级，如何求出整个树在以y为根的情况下的最大得分？可以发现，为了计算整棵树的得分，我们可以将其划分为两部分，一是原先以y为根节点的子树，二是以x为根节点的子树减去以y为根节点的子树的部分，这样，我们可以分别计算两者对最大得分的贡献；可以知道，第一部分就是已知的「以y为根节点的最大得分」，而第二部分可以用「以x为根节点的最大得分」减去「以y为根节点的最大得分」得到，但需要注意的是，如果「以y为根节点的最大得分」小于0，那么实际上在计算「以x为根节点的最大得分」时并没有算入「以y为根节点的最大得分」，因此不需要减；同时如果减以后得到的贡献小于0，我们也不需要将其再算入最大得分
        # 以上同样可以用dfs的方式实现，因此总共只需两次dfs即可求出答案

        myMax = lambda x,y : x if x>y else y
        g = [[] for _ in range(n)] # 建图
        for a,b in edges:
            g[a].append(b)
            g[b].append(a)

        for i in range(n): # 重新赋值
            if good[i] == 0:
                good[i] = -1

        dp= [0]*n
        def dfsUp(x, pa):
            # 求出在以0为根节点的子树中，以各个节点为根节点的子树的最大得分
            ans = good[x]
            for y in g[x]:
                if y != pa:
                    ans += myMax(0, dfsUp(y, x)) # 如果贡献小于0，则不计入
            dp[x] = ans
            return ans
        
        dfsUp(0, -1)
        res = [0]*n
        res[0] = dp[0]

        def dfsDown(x, pa):
            for y in g[x]:
                if y != pa:
                    restVal = res[x]-myMax(0, dp[y]) # 算出大子树除去小子树部分后，对整个树的贡献
                    res[y] = dp[y]+myMax(0, restVal) # 两部分相加，即可求出以x为根节点时整棵树的最大得分
                    dfsDown(y, x)
        
        dfsDown(0, -1)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 3
    edges = [[0,1],[1,2]]
    good = [1,0,1]
    print(s.maxSubgraphScore(n, edges, good))
