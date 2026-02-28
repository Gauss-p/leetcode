from typing import List

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        # 采用黑白染色法，如果从一个图中任意一个节点出发，将它标记为白色，接下来将它周边的所有点标为黑色，在将黑色的点周边的所有未标记的点标为白色，这样，在这个图中，所有白色的点中任意一个点都和其他的点的距离是偶数，所有黑色的点也一样，那么我们可以发现无论从哪个点开始填涂，最终效果都是一样的，无非是黑色和白色换了一下而已
        # 那么和上一道题目同理，对于第二个图我们只需要找到其中最大的单个点对应的目标节点数量即可，那么用dfs的方法，同时在函数中用0表示当前层需要填涂白色，用1表示当前层需要填涂黑色，而我们需要做的只是统计第二个图中填涂完成后黑色节点和白色节点的数量最大值，这样我们就可以首先确定对于第一个图中每一个节点，在第二个图中的目标节点数量
        # 接下来，对于第一个图，我们可以用同样的涂色方法(从任何一个节点开始填涂都没关系)，还是用dfs的算法，对于每一个节点，用0表示白色，用1表示黑色，同时统计出整个图中黑色节点和白色节点的个数。但是由于对于第一个图中每一个节点都还需要计算在当前图中目标节点的数量，因此我们需要知道每一个节点的颜色，这样只需要求出第一个图中和它颜色相同的总节点数，累加答案即可
        # 那么由于两张图我们都需要用dfs，函数主体相同，因此可以在函数中加一个标识数字flag，用来区别当前是在哪一个图中，然后分两个图来操作即可

        n = len(edges1)+1

        def build_tree(edges): # 建图函数
            n = len(edges)+1
            g = [[] for _ in range(n)]
            for a, b in edges:
                g[a].append(b)
                g[b].append(a)
            return g

        cnt1 = [0,0] # cnt1[0]统计第一个图中白色节点数量，cnt1[1]统计第一个图中黑色节点数量
        cnt2 = [0,0] # cnt2[0]统计第一个图中白色节点数量，cnt2[1]统计第一个图中黑色节点数量
        colors = [0]*n # 记录第一个图中每一个节点的颜色
        def dfs(x, pa, d, g, flag):
            if flag==1:
                # 对第一个图操作
                colors[x] = d
                cnt1[d] += 1
            else:
                # 对第二个图操作
                cnt2[d] += 1
            for y in g[x]:
                if y == pa:
                    # 防止死循环
                    continue
                dfs(y, x, d^1, g, flag)

        g1, g2 = build_tree(edges1), build_tree(edges2) # 建图
        dfs(0, -1, 0, g1, 1) # 统计第一个图中黑白两色的节点数量，以及记录各个节点的颜色
        dfs(0, -1, 0, g2, 2) # 仅统计第二个图中黑白两色的节点数量
        tree2max = max(cnt2) # 求出第二个图中最大的单个点对应的目标节点数量
        res = [tree2max]*n
        for i in range(n):
            res[i] += cnt1[colors[i]] # 在当前图中只需找相同颜色的节点即可
        return res

if __name__ == "__main__":
    s = Solution()
    edges1 = [[0,1],[0,2],[2,3],[2,4]]
    edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
    print(s.maxTargetNodes(edges1, edges2))
