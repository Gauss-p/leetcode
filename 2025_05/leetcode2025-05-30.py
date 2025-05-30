from typing import List
from collections import defaultdict

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        # 两种思路，第一种是用bfs从两个节点分别出发记录到各个点的距离，从而在之后遍历所有点求出答案
        # 第二种是用bfs从两个节点分别出发记录尽可能长的一条路径，在之后遍历两条路径找答案

        # 第一种
        # n = len(edges)
        # def bfs(x):
        #     dis = [float("inf")]*n # dis[i]标识从x到i的路径长度
        #     # dis[x] = 0
        #     d = 0
        #     while x >= 0 and dis[x] == float("inf"):
        #         dis[x] = d
        #         d += 1
        #         x = edges[x]
        #     return dis

        # d1, d2 = bfs(node1), bfs(node2)
        # res = -1
        # tot = float("inf")
        # for i in range(n):
        #     curMax = max(d1[i], d2[i])
        #     if curMax < tot:
        #         # 这里因为遍历的节点编号有序，因此不需要判断节点编号大小问题，只需要判断到两个点的距离较大值即可
        #         res = i
        #         tot = curMax
        # return res

        # 第二种
        n = len(edges)
        def bfs(x):
            visited = [0]*n
            path = [] # 记录从x开始的一条路径
            while x>=0 and visited[x] == 0:
                # -1不应该被加入，因为visisted[-1]代表最后一个元素，不会报错
                # 遇到-1即意味着从x出发的点到了尽头
                path.append(x)
                visited[x] = 1
                x = edges[x]
            return path
        
        p1 = bfs(node1) # 两条路径
        p2 = bfs(node2)
        dis2 = defaultdict(int) # 因为路径是按顺序存储的，所以其中的索引就代表了到那个节点的路径长度
        for i in range(len(p2)):
            dis2[p2[i]] = i+1 # 将路径转换为到每个点的距离，加1是为了和defaultdict的初始值0区分
        
        res = float("inf")
        tot = float("inf")
        for i in range(len(p1)):
            cur_node = p1[i]
            if dis2[cur_node] == 0:
                continue
            tmpDis = max(i+1, dis2[cur_node])
            if tmpDis < tot:
                # 比较到两个点的距离较大值
                res = cur_node
                tot = tmpDis
            elif tmpDis == tot:
                # 因为cur_node是无序的，因此需要比较节点编号的大小
                res = min(res, cur_node)
        return -1 if res == float("inf") else res

if __name__ == "__main__":
    s = Solution()
    edges = [2,2,3,-1]
    node1 = 0
    node2 = 1
    print(s.closestMeetingNode(edges,node1,node2))
