from typing import List
from functools import cache

class Solution:
    def maximumPoints(self, edges: List[List[int]], coins: List[int], k: int) -> int:
        if k == 0:
            # 特殊情况，当k为0时，答案就是coins中所有值之和
            return sum(coins)
        if len(set(coins)) == 1 and coins[0] == k:
            # 特殊情况，当coins中所有值都为k时，答案就是从头开始依次除以2^1,2^2...的商之和
            return sum(coins[i]>>(i+1) for i in range(len(coins)))
        n = len(edges)+1
        g = [[] for _ in range(n)]
        for x,y in edges:
            g[x].append(y)
            g[y].append(x)
        visited = [0]*n
        @cache
        def dfs(x, div):
            # 无论如何都是两种情况，第一种是在祖先总共除2的基础上再除以2，因为这里的除法我是用位运算来表示的，所以对于第一种情况就是右移div+1(div就是祖先累计除以2的次数)，那么第二种是在祖先累计除以2的基础上减去k，所以第二种情况的就是右移div之后减去k即可
            if len(g[x]) == 0:
                # 如果x是叶子节点，那么就直接返回两种情况的最大值
                return max(coins[x]>>(div+1), (coins[x]>>div)-k)
            visited[x] = 1 # 防止混乱，即防止出现先孩子后祖先的情况
            first = coins[x]>>(div+1) # 第一种情况的起始值
            second = (coins[x]>>div)-k # 第二种情况的起始值
            for y in g[x]:
                if visited[y] == 0:
                    # 因为第一种情况多除以了2，所以继续往后的时候需要将div+1
                    first += dfs(y, div+1)
                    second += dfs(y, div)
            visited[x] = 0
            return max(first, second) # 最后返回两种情况的最大值即可
        return max(dfs(0, 0), dfs(0, 1))

if __name__ == "__main__":
    s = Solution()
    edges = [[0,1],[1,2],[2,3]]
    coins = [10,10,3,3]
    k = 5
    print(s.maximumPoints(edges, coins, k))
