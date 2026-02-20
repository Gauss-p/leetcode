from typing import List
from collections import deque

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        if k == 0:
            return [1]*(len(edges1)+1)
        
        # 首先根据edges1和edges2分别建出第一个图和第二个图g1和g2，接下来用bfs的方法，在g1中从每一个节点出发，一层一层地循环，一共循环k层，在循环的同时进行统计，这样我们就得到了在g1中从每一个节点出发路径数量小于等于k的目标节点，将它们按顺序存入列表d1中
        # 同时我们还需要计算g2，但是需要注意的是，如果用一条边连接了两个图，那么对于g1中的每一个点，如果要在g2中找路径数量小于等于k的节点，就需要从g2中被连接的那个节点出发，寻找在g2中路径数量小于k的节点数量。那么与上面的bfs同理，只需将路径长度限制改为k-1，同时更改图为g2即可
        # 于是我们可以编写一个函数generate_dis，传入一个图和一个路径长度限制，用来计算该图中从各个节点出发有多少个节点满足到这个节点的路径长度小于等于给出的限制的，同时我们还有一个bfs函数，传入一个图和一个点以及路径长度限制，返回从当前点开始，满足与当前点的距离小于等于限制的点的个数，也就是说，generate_dis函数只需对每个节点调用一次bfs函数即可

        def generate_dis(edges, k):
            n = len(edges)+1
            g = [[] for _ in range(n)]
            for a,b in edges:
                g[a].append(b)
                g[b].append(a)

            res = []
            for i in range(n):
                # 对每个点计算一次
                res.append(bfs(g, i, k))
            return res

        def bfs(g, i, k):
            n = len(g)
            q = deque()
            q.append(i)
            visited = [0]*n # 防止重复计算
            ans = 0
            depth = 0 # 防止路径超出限制
            while q and depth<k:
                depth += 1
                cur = []
                for x in q:
                    # 每次更新为下一层
                    visited[x] = 1
                    for y in g[x]:
                        if visited[y]:
                            continue
                        cur.append(y)
                        ans += 1
                q = cur
            return ans

        d1, d2 = generate_dis(edges1, k), generate_dis(edges2, k-1) # 注意第二张图只需要k-1的长度
        tree2max = max(d2)+1 # 并且我们只需要取第二张图满足条件的最大值即可，每次连接只连接只一个点
        res = [0]*(len(edges1)+1)
        for i in range(len(edges1)+1):
            res[i] = d1[i]+tree2max+1
        return res

if __name__ == "__main__":
    s = Solution()
    edges1 = [[0,1],[0,2],[2,3],[2,4]]
    edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
    k = 2
    print(s.maxTargetNodes(edges1,edges2,k))
