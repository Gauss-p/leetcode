from typing import List

class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        # 读题，可以发现题目只要求我们删除两条边，因此假设当前我们已经确定要删除的两条边分别是：x和x的父节点之间的边，以及y和y父节点之间的边，需要计算的是三个连通块的异或最大值和最小值，接下来需要做的就是将所有可能的两条边遍历后分别计算求答案即可
        # 首先，我们应如何计算一个连通块中所有元素的异或值呢？可以考虑前缀异或和的方式，将给出的图看作一个树(由于题目并没有规定哪个节点是根，因此我们可以假设根节点为0)，并分别计算出以每一个节点为根节点的子树中所有元素的异或值，为了方便之后的计算，我们可以用列表xor存储所有子树的异或和，即用xor[a]表示以a为根节点的子树中所有节点的异或和。这样，假如我们要求的是整个树中去掉以x为根节点的子树后剩余元素的异或和，就可以利用异或的特性，直接计算xor[0]^xor[x]即可得到，因为相同元素异或两边后就变成了0，对答案也就毫无影响了
        # 这样的话，我们可以将一个连通块看作由一个大树中去掉一个或两个小树后得到的一个区域，也就是说，一个连通块中的异或和就可以用xor[a]^xor[b]或xor[a]^xor[b]^xor[c]来计算，后面异或多少个数就相当于在大树中减去多少个小树
        # 但是对于删除的两条边的位置不同的情况，我们计算连通块中异或和的方式也不同。一共有三种不同的情况：
        #   1.如果节点x和y在同一棵子树中，且x在树中的层级更高，也就是说x是y的祖先，那么分成的三个连通块就分别是：原树减去子树x，子树x减去子树y，以及子树y，因此三个连通块的异或和就分别是：xor[0]^xor[x], xor[x]^xor[y], xor[y]
        #   2.如果节点x和y在同一棵子树中，且y在树中的层级更高，那么分成的三个连通块就分别是：原树减去子树y，子树y减去子树x，以及子树x，因此三个连通块的异或和就分别是：xor[0]^xor[y], xor[y]^xor[x], xor[x]
        #   3.如果节点x和y分居两棵子树中，那么分成的三个连通块就分别是：原树减去子树x再减去子树y，子树x，以及子树y，因此三个连通块的异或和就分别是：xor[0]^xor[x]^xor[y], xor[x], xor[y]
        # 通过以上的分析，我们可以发现，如果要计算不同情况，我们还需要快速判断两个点是否存在祖先关系，这里我们可以用时间戳来判断。由于在计算所有子树的异或和时需要用到dfs进行计算，因此我们可以在dfs计算的同时记录下访问各个节点的时间戳，以此判断两个节点的祖先关系
        # 首先我们分析一下dfs的运行过程，假如x和y同属一棵子树，且y的深度更大，那么dfs应当先访问x，然后再访问到y，然后退出y，最后退出x，也就是说，访问的过程应当是:x->y->y->x，因此记录下的时间戳应当满足：进入x的时间小于进入y的时间，且退出y的时间小于等于退出x的时间(注意这里的小于等于是因为dfs在一级一级归回去的时候时间戳并不会累加，也就造成了可能y和x的退出时间相同)；接下来，假如x和y不同属一棵子树，那么dfs的访问顺序就应当是先访问x，然后退出x，再访问到y，最后退出y，也就是x->x->y->y，因此记录下的时间戳应当满足：退出x的时间小于进入y的时间
        # 综上，我们为了判断祖先关系，就应当记录下每一个节点的访问时间inTime[i]和退出时间outTime[i]，最后根据这两个判断x和y的祖先关系即可。同时，可以发现，如果x不是y的祖先，y也不是x的祖先，就说明x和y一定分属两棵子树，因此我们只需要一个函数判断给出的a和b是否有祖先关系即可。
        n = len(nums)
        g = [[] for _ in range(n)]
        for a,b in edges:
            g[a].append(b)
            g[b].append(a)
        
        clock = 0
        xor, inTime, outTime = [0]*n, [0]*n, [0]*n # 分别记录每一个子树的异或和，每一个节点的访问时间和退出时间
        def dfs(x, pa):
            nonlocal clock
            clock += 1 # 维护时间戳单调递增
            inTime[x] = clock # 记录访问时间
            xor[x] = nums[x]
            for y in g[x]:
                if y != pa:
                    dfs(y, x)
                    xor[x] ^= xor[y] # 计算子树x的异或和
            outTime[x] = clock # 记录退出时间
        dfs(0, -1)

        def is_pa(x, y):
            # 判断x是否为y的祖先
            return inTime[x] < inTime[y] and outTime[y] <= outTime[x]

        res = float("inf")
        for x in range(1, n):
            for y in range(x+1, n):
                if is_pa(x, y):
                    # 第一种情况
                    a, b, c = xor[y], xor[x]^xor[y], xor[0]^xor[x]
                elif is_pa(y, x):
                    # 第二种情况
                    a, b, c = xor[x], xor[y]^xor[x], xor[0]^xor[y]
                else:
                    # 第三种情况
                    a, b, c = xor[x], xor[y], xor[0]^xor[x]^xor[y]
                res = min(res, max(a, b, c)-min(a, b, c)) # 记录答案
                if res == 0:
                    # 减少循环次数
                    return 0
        return res

# class ufs:
#     def __init__(self, n, nums):
#         self.pa = list(range(n))
#         self.val = nums.copy()
    
#     def find(self, x):
#         if self.pa[x] != x:
#             self.pa[x] = self.find(self.pa[x])
#         return self.pa[x]

#     def union(self, x, y):
#         px, py = self.find(x), self.find(y)
#         if self.val[px] > self.val[py]:
#             self.pa[py] = self.pa[px]
#             self.val[px] ^= self.val[py]
#             self.val[py] = -1
#         else:
#             self.pa[px] = self.pa[py]
#             self.val[py] ^= self.val[px]
#             self.val[px] = -1

# class Solution:
#     def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
#         n = len(nums)
#         def calc(a, b):
#             curUfs = ufs(n, nums)
#             for i in range(n-1):
#                 if i == a or i == b:
#                     continue
#                 x, y = edges[i]
#                 curUfs.union(x, y)
#             mn, mx = float("inf"), 0
#             for i in curUfs.val:
#                 if i != -1:
#                     if i<mn:
#                         mn = i
#                     if i>mx:
#                         mx = i
#             return mx-mn

#         res = float("inf")
#         for i in range(n-1):
#             for j in range(i+1, n-1):
#                 cur = calc(i, j)
#                 if cur < res:
#                     res = cur
#         return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,5,5,4,11]
    edges = [[0,1],[1,2],[1,3],[3,4]]
    print(s.minimumScore(nums, edges))
