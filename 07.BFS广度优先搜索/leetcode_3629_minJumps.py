from typing import List
from collections import defaultdict


# 题目是有关质数的，因此我们首先可以想到筛法求质数，但是注意到题目中质数传送的部分是由数组中任意一个质数传送到另外一个是该质数的倍数的地方，所以单纯的求出质数是不行的，我们需要利用筛法求出所有数字的质因数，或者在筛法求质数的同时记录每一个质数的倍数，接下来的分析中，我们可以看到第一种方法是更方便的
# 在这道题目中，在每一个节点起跳的情况都有所不同，如果当前节点不是质数，那么它就可以跳到两边的相邻位置，而如果当前节点是质数，那么它不仅可以跳到两边的相邻位置，还可以跳到数组中任意一个是当前质数的倍数的位置，因此，在计算中，我们可以将给出的nums看作一个图，其中从一个节点跳到另一个节点就可以看作是两个节点之间有一条有向边，我们需要做的就是求出节点0到节点n-1之间的最短路径，这可以用Dijkstra的方法来求，不过由于这里每一条边的权重为1，我们还可以用BFS的方式一圈一圈地向外找，一直到第一次找到n-1的节点就返回已找的圈数，这样也可以保证路径长度最短
# 为了实现BFS算法，我们需要先建图，也就是构建图中的边。如何构建呢？这里对应第一段中的两种方法，边也有两种建法。对应第一种求质因数的方法，我们可以这样想，对于任意一个位置，如果当前是一个和数，就说明在这个数组中的其他位置如果有该数字的质因数，那么这些质因数就可以跳转到当前位置，因此我们创建一个字典g，其中键是质数，而每一个质数对应的值就是该质数可以跳转到的位置，这样，在BFS中，我们只需要找到当前索引对应的值，并找出该值在g中对应的可以跳转到的位置，就说明当前索引和这些位置中有一条有向边，但注意，这样在BFS中会少算i+1和i-1两个位置，因此我们还需判断后将这两个位置算入当前索引的出边中
# 对应第二种求质数的倍数的方法，解释在第二段代码的注释中
# 最后，在连完所有边后，剩下的就是BFS了，我们只需按照层序遍历的样子，从0开始，一层一层向外查找，一直到找到n-1为止即可返回已查找的圈数，但是注意，为了防止内存超限，我们还需要在每一次遍历完一组可跳转的点时清空当前的所有点，这样可以防止在之后又一次调用该组可跳转点导致重复计算

MAX_NUM = 1000001
dic = [[] for _ in range(MAX_NUM)]
for i in range(2, MAX_NUM):
    if len(dic[i]) > 0: # 用质因数数组为空来标记该数字为质数
        continue
    for j in range(i, MAX_NUM, i):
        # 记录所有数字的质因数，其中i是j的因数
        dic[j].append(i)

class Solution:
    def minJumps(self, nums: List[int]) -> int:
        myMax = lambda x,y : x if x>y else y
        myMin = lambda x,y : x if x<y else y

        n = len(nums)

        g = defaultdict(list)
        for i in range(n):
            for p in dic[nums[i]]:
                # 存储每一个对应值为质数p的位置可以跳转的所有位置
                g[p].append(i)

        q = [0]
        visited = [0]*n
        res = 0
        while len(q):
            cur = q.copy()
            q = []
            for x in cur:
                if visited[x] == 1:
                    continue
                visited[x] = 1
                if x == n-1:
                    # 这个判断既可以减少循环，也可以在之后的判断中去除x=n-1的可能
                    return res

                indxs = g[nums[x]] # x位置的数字可以跳转的所有位置
                indxs.append(x+1) # 由于x!=n-1，所以x+1一定合法
                if x>0:
                    indxs.append(x-1)
                for y in indxs:
                    q.append(y) # 继续下一层
                g[nums[x]].clear()
            res += 1

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,4,6]
    print(s.minJumps(nums))
