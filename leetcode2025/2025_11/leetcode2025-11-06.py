from typing import List
from heapq import *

class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        # 分析题目，我们需要做的是将所有的电站分成多个不同的组，对于每一个查询，如果操作编号为1，也就意味着我们需要修理当前电站，那么我们需要首先判断它是否离线，如果离线，就要在被操作电站所在的这个组中寻找最小的一个在线电站，否则直接将当前电站作为答案即可；如果操作编号为2，直接将当前电站标记为离线即可
        # 为了快速求出一个组中编号最小的电站，我们可以使用小顶堆，而如何将各个组中元素分别加入不同的小顶堆，则可以采用dfs的方式，从每一个未被标记过的节点开始搜索，将和它连通的所有节点都进行标记，同时加入相应的小顶堆中，即可实现上述要求
        # 接下来，我们需要实现上述对于两个编号的操作。在此之前，我们需要用一个列表offLine记录所有电站的在/离线情况，这样可以帮助我们在寻找编号最小的在线电站时更方便地标记。首先，对于编号为2的操作，我们直接将对应点的offLine值改为true即可，这是最简单的；其次，对于编号为1的操作，如果当前电站并没有被标记离线，那么根据题目我们直接将它计入答案即可；最后，如果编号为1且当前电站离线，我们就需要找出当前电站所在的小顶堆，将其取出，称为h，然后在这个时候，直接将堆顶的所有离线电站全部删除，最后将堆顶元素计入答案即可
        # 注意，当一个电站离线的时候，我们并不需要对它所在的小顶堆进行操作，而是将所有的删除操作全部放在最后一种情况的处理时，这种方法叫做懒删除，效率更高
        g = [[] for _ in range(c+1)] # 建图
        for x,y in connections:
            g[x].append(y)
            g[y].append(x)
        
        belong = [-1]*(c+1) # 记录每一个元素属于索引为几的小顶堆
        heaps = [] # 保存所有小顶堆

        def dfs(x):
            h.append(x) # 在当前小顶堆中记录当前点
            belong[x] = len(heaps) # 由于当前小顶堆并没有加入heaps中，因此当它加入后索引一定是现在的len(heaps)
            for y in g[x]:
                if belong[y] < 0:
                    dfs(y)

        for i in range(1, c+1):
            if belong[i] >= 0: # 跳过已经被标记的点
                continue
            h = []
            dfs(i)
            heapify(h)
            heaps.append(h)

        offLine = [False]*(c+1)
        res = []
        for op, x in queries:
            if op == 2:
                offLine[x] = True # 直接标记离线
                continue
            
            if offLine[x] == False: # 当前电站并未离线
                res.append(x)
                continue
            
            h = heaps[belong[x]]
            while h and offLine[h[0]]: # 删除堆顶所有离线电站
                heappop(h)
            res.append(h[0] if h else -1)
        
        return res

if __name__ == "__main__":
    s = Solution()
    c = 5
    connections = [[1,2],[2,3],[3,4],[4,5]]
    queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]
    print(s.processQueries(c, connections, queries))
