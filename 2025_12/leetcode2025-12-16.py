from typing import List

class Solution:
    def maxProfit(self, n: int, present: List[int], future: List[int], hierarchy: List[List[int]], budget: int) -> int:
        # 可以发现，对于每一个员工，实际上都有两种情况：买或不买，但是如果他买，根据购买价格又可以分出两种情况，一种是半价购买，另一种则是全价购买。这样看来，为了计算最大利润，我们最好就选择动态规划的思路，毕竟这种算法最符合我们对题目的分析，注意到根据题目给出的从属关系我们又可以将所有员工按照"上司->下属"的方式排列成一棵树，因此我们便可以考虑在对树的DFS的过程中，同时对每个点进行动态规划计算最大利润
        # 定义dfs函数，其中仅传入一个参数x，返回值为：从x开始，各个成本价所对应的最大利润值，故返回值应当是一个长度为budget+1的列表，但是注意由于我们可以半价购买或是全价购买，因此还需要有一个变量标识该最大利润值是员工x通过半价购买得到的还是通过全价购买得到的(这里的全价或半价和x下面的员工无关，它只标识员工x的付款情况)，故我们用0表示全价购买，1表示半价购买，因此返回值就应是一个2*(budget+1)的二位列表
        # 对于一个节点x，我们接下来考虑它的状态转移方程，定义数组subF表示从x的各个孩子节点开始，各个成本价对应的最大利润值。因此用y循环x的所有子树，分别传入dfs进行计算即可得到从y开始各个成本价对应的最大利润值，之后我们便可以采用背包问题的思路，对于每一个成本价cost和其对应的最大利润值profit，我们都更新subF中所有大于cost的成本价对应的最大利润值：即，用costTot循环所有大于cost的成本价，且由于costTot限定了成本价，同时我们还需要单独出cost的成本换取profit的利润，因此可以得到：subF[costTot] = subF[costTot-cost]+profit，最后对于所有成本对应的利润取最大值即可。需要注意的是，我们在subF中还有一维变量用来表示是否半价购买，因此我们需要分别计算subF[0]中对应的最大利润和subF[1]中对应的最大利润，同时在计算的时候，为了防止覆盖，我们可以用一个新列表先行计算，然后再直接赋值给subF即可
        # 接下来，计算完subF，我们还需要知道从x开始各个成本对应的最大利润，注意到我们最开始算的是从x的孩子节点开始，各个成本价对应的最大利润，因此还需要将它们对应的加上员工x可以获得的利润。我们同样需要分两个列表进行计算。定义答案列表为f，那么同样分别计算f[0]和f[1]，如果x不购买，那么下面第一层所有的人都必须以全价购买，因此无论如何f[0]和f[1]的初始值都应当是subF[0]。接下来，如果x购买且是全价购买，那么x可以贡献的利润值就是future[x]-present[x]，否则，如果x购买且是半价购买，那么x可以贡献的利润值就是future[x]-present[x]//2，最后，由于x购买了，因此x下面一层的所有员工都可以享受半价购买的权利，因此我们循环subF[1]，即x下面一层员工全部按半价购买，然后将各个最大利润加上x可以贡献的利润，和f中对应位置取最大值即可
        g = [[] for _ in range(n)]
        for x,y in hierarchy:
            g[x-1].append(y-1) # 建图
        
        def dfs(x):
            subF = [[-float("inf")]*(budget+1) for _ in range(2)] # 记录x的所有子树在各个成本价之下可以获得的最大利润
            subF[0][0] = 0 # subF[0]记录x所有子节点按照全价购买时能够获得的最大利润
            subF[1][0] = 0 # subF[1]记录x所有子节点按照半价购买时能够获得的最大利润

            for y in g[x]:
                fy = dfs(y) # 求出当前子树各个成本价对应的最大利润
                for k in range(2):
                    nf = [-float("inf")]*(budget+1) # 新建列表计算
                    nf[0] = 0
                    for cost, profit in enumerate(fy[k]):
                        if profit < 0:
                            continue
                        for costTot in range(cost, budget+1):
                            nf[costTot] = max(nf[costTot], subF[k][costTot-cost]+profit) # 背包问题解决方式
                    subF[k] = nf
            
            f = [None]*2
            for k in range(2):
                f[k] = subF[0].copy() # x不买，则x所有下属需全价购买
                cost = present[x]//(k+1)
                for costTot in range(cost, budget+1):
                    f[k][costTot] = max(f[k][costTot], subF[1][costTot-cost]+future[x]-cost) # x买，则x所有下属可半价购买
            return f
        
        return max(dfs(0)[0]) # 注意返回值必须要[0]，表示根节点无论如何得按照全价购买

if __name__ == "__main__":
    s = Solution()
    n = 2
    present = [1,2]
    future = [4,3]
    hierarchy = [[1,2]]
    budget = 3
    print(s.maxProfit(n, present, future, hierarchy, budget))
