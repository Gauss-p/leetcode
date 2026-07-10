from typing import List
from collections import defaultdict

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        # 本题要求对每一个查询的节点对(u,v)求出两者之间的最短距离。
        # 首先，如果要找到给出节点中的所有有效边，需要先将所有节点按照nums中的值从小到大排序，但由于查询时需要根据初始索引来查找，故不能直接排序，需要对每一个节点i都将(nums[i], i)保存到新数组中，对新数组排序。之后利用双指针即可得到新数组中哪些节点可以组成边，只需要利用原下标到新下标的映射数组即可得到原数组中哪些节点可以组成边。
        # 注意，在用双指针求有效边时，不需要将所有边都求出来，对于一个点i，如果它要往前跳并且要让它跳的步数最少，就必须要让和它连接的左端点尽可能的远，故对于每一个点都需要求它左边最远的可以和它连接的点。
        # 之后，利用倍增法可求出每一个点往左跳2**k步可以到达的最远点，那么对于一组查询节点对(u,v)，若u<v，则可以将v在不超过u的情况下不断向左跳，这样，当不能再跳的时候，即表明此时节点v只要再往左跳一个点即可跳到超过u的位置，故一定能够达到u。
        # 注意，在将v向左跳的时候，为了保证让跳的步数尽可能大并且不会跳超过u，需要对所有可能的二进制位进行从大到小循环，如果跳了以后不会超过u就可以跳，否则就不能跳，这样即可在结束跳跃时最接近u
        # 最后，如果两者不在一个连通域内，则v在跳跃结束后就算再往左跳也不会超过u，答案即为-1，否则答案即为跳跃过程中的累加值
        newNums = []
        for i in range(n):
            newNums.append((nums[i], i))
        newNums.sort()
        dic = defaultdict(int) # 创建索引映射字典
        for i in range(n):
            dic[newNums[i][1]] = i
        
        m = n.bit_length()
        pa = [[-1]*m for _ in range(n)]
        i = 0
        for j in range(n): # 计算每一个点向左一次跳跃后能够达到的最远点
            while i<=j and newNums[j][0]-newNums[i][0]>maxDiff:
                i += 1
            pa[j][0] = i
        
        for i in range(n):
            for j in range(1, m): # 填入祖先数组
                pa[i][j] = pa[pa[i][j-1]][j-1]
        
        res = []
        for u,v in queries:
            if u == v:
                res.append(0)
                continue
            a, b = dic[u], dic[v]
            if a > b: # 保证a在b左侧
                a, b = b, a
            steps = 0
            for i in range(m-1, -1, -1):
                if pa[b][i] > a:
                    b = pa[b][i]
                    steps += (1<<i) # 注意由于跳跃的是2**i，路径长度需要加这么多
            if pa[b][0] > a: # 不在一个连通域内
                res.append(-1)
            else:
                res.append(steps+1) # 最后还剩下一步，需要加上
        return res

if __name__ == "__main__":
    s = Solution()
    n = 5
    nums = [1,8,3,4,2]
    maxDiff = 3
    queries = [[0,3],[2,4]]
    print(s.pathExistenceQueries(n, nums, maxDiff, queries))
