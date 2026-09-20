from typing import List

class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        # 举个例子，如示例1，如果我们从0节点开始，记录访问0节点的时间为1，那么访问3的时间就是2，访问2的时间就是3，访问4的时间就是4，再次访问3的时间就是5，在这个过程中，出现了两次节点3，说明出现了环路，这时候我们如果将两次访问3的时间相减，就得到了环路的长度:5-2=3，因此我们可以通过记录时间的方式得到最大的环路长度
        # 但是我们发现一个问题，就是如果这样计算，可能会多次重复计算到同一个环路，但是我们有需要从每一个节点开始查找，怎么办？我们只需要保证记录时间的变量是单增的即可，这样，只要在当前起始时间之后访问的所有节点都是本次循环找到的节点，只需要对比时间戳即可
        n = len(edges)
        visited = [0]*n
        curTime = 1
        res = -1
        for x in range(n):
            # 每次保存起始时间，方便比较时间戳来避免重复计算
            startTime = curTime
            while x!=-1 and visited[x]==0:
                # 因为每个节点至多只有一条出边，所以用while循环即可遍历到所有联通节点
                visited[x] = curTime
                x = edges[x]
                curTime += 1
            if x!=-1 and visited[x]>=startTime:
                # 如果当前循环到的环路没有被计算过，就记录它的长度
                res = max(res, curTime-visited[x])
        return res
        # 下面是超时的dfs
        # res = -1
        # n = len(edges)
        # visited = defaultdict(int)
        # @cache
        # def dfs(b, x, length, path):
        #     if x == b:
        #         nonlocal res
        #         res = max(res, length)
        #         return
        #     if x != -1 and (path>>x)&1==0:
        #         path |= (1<<x)
        #         dfs(b, edges[x], length+1, path)
        #         path ^= (1<<x)
        # for i in range(len(edges)):
        #     dfs(i, edges[i], 1, 1<<i)
        # return res

if __name__ == "__main__":
    s = Solution()
    edges = [3,3,4,2,3]
    print(s.longestCycle(edges))
