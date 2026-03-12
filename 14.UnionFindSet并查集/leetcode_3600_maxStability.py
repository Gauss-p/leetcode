from typing import List

class UnionFindSet:
    def __init__(self, n):
        self.pa = list(range(n))
        self.cnt = n

    def find(self, x):
        if x != self.pa[x]:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        self.pa[px] = py
        self.cnt -= 1
        return True

class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        # 首先，考虑一下特殊情况，在什么情况下可以直接返回-1而不需要计算答案呢？根据题目对生成树的要求，需要保证它是连通的，同时需要保证它是无环的，因此，在给出的所有边中，如果所有的必须包含的边已经构成了一个环，或者所有的边加起来都无法保证将每一个节点连通的话，就可以直接返回-1
        # 那么该如何判断是否能够连通呢？其实需要做的就是统计连通块的个数，如果个数为1，那么就说明edges中的所有边是联通的，只要大于1就一定不连通。可以考虑并查集的方法，在并查集中，有一个函数union专门用来合并两个点，那么只要两个点被合并，这个树中的连通块就少了一个，因此维护一个变量cnt用来存储tree中连通块的个数，在union中只要成功合并两个节点，就将cnt减掉1。那么cnt的初始值就应该是节点总个数n。因此，只要将edges中的所有边连起来，如果cnt依然大于1，就直接返回-1即可
        # 接下来，又该如何判断must=1的所有边是否构成环路呢？同样，可以在union中处理，这里就对所有must=1的边单独合并，先不考虑must=0的边，接下来，对于每一条must=1的边(x,y)，如果查找到x的祖先和y的祖先竟然是同一个，说明在当前边加入之前，已经有一些must=1的边将x和y连接起来了，假如这时再将(x,y)边加入，就一定会构成一个环路，因此为了标记，就直接返回False即可，而对应的，如果成功合并，就返回True。所以说union的返回值就变为了是否可以成功合并
        # 那么在判断完以上两种特殊情况后，剩下的就一定是合法的树，那么为了找到最大的稳定性，可以考虑二分查找，定义check(mn)函数，用来判断是否可以将edges中的部分边权重的最小值变成mn，且这些边还能够构成一个合法的生成树
        # 在check函数中，同样用并查集的算法来判断是否可以构成合法生成树，首先，如果在强制边中有某些边的权重小于了mn，那么此时一定无法构成权重最小值为mn的合法生成树，因此返回False，接下来，先将所有权重大于等于mn的边合并，然后再将进行一次升级后能够权重大于等于mn的边合并，注意升级次数不能超过k，最后判断，该并查集中的连通块个数是否变成了1即可
        mustUfs = UnionFindSet(n)
        allUfs = UnionFindSet(n)
        vMin, vMax = float("inf"), 0
        for x, y, v, must in edges:
            if must and not mustUfs.union(x, y):
                # 在合并的同时判断强制边是否构成环路
                return -1
            allUfs.union(x, y)
            vMin = min(vMin, v) # 记录最大最小边权值用于二分查找
            vMax = max(vMax, v)
        if allUfs.cnt > 1:
            # 所有边合起来都无法构成连通树
            return -1

        def check(mn):
            u = UnionFindSet(n)
            for x, y, v, must in edges:
                if must and v<mn:
                    # 强制边权值小于mn，无法构成需要的生成树
                    return False
                if v >= mn:
                    u.union(x, y)

            leftK = k # 升级次数限制
            for x, y, v, must in edges:
                if leftK==0 or u.cnt==1:
                    break
                if not must and v<mn and 2*v>=mn and u.union(x, y): # 这里在判断环路的同时合并边
                    # 合并所有可升级的边
                    leftK -= 1
            return u.cnt==1

        left, right = vMin, vMax*2 # 二分查找
        while left<=right:
            mid = (left+right)//2
            if check(mid):
                left = mid+1
            else:
                right = mid-1
        return right

if __name__ == "__main__":
    s = Solution()
    n = 3
    edges = [[0,1,2,1],[1,2,3,0]]
    k = 1
    print(s.maxStability(n, edges, k))
