from typing import List

class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        # 注意到题目中保证了树中所有节点之和是k的倍数，因此我们只要分割出一个总和可以被k整除的连通块，剩下的所有节点总和就一定可以被k整除，因此我们可以贪心地想，在树中从最底部开始向上查找，只要找到一个和可以被k整除的时刻就将树在该位置进行分割，这样不仅可以保证分割出的连通块和剩余连通块的和均可以被k整除，同时可以保证分割出来的每一个目标连通块的规模都最小，也就是分割出来的连通块数量最大
        # 为了实现这个分割思路，我们可以采用dfs的方式，其中传入一个索引x和其父节点pa，计算结果就是以x为根节点的子树中所有元素的总和，那么由于我们是在递归中“归”的时候累加的，因此可以保证是从叶子节点开始向上算起，这样，只要计算出的子树总和是k的倍数，我们就将答案中的连通块数量加1，表示从x这个位置开始，向下划分出一个新的连通块
        # 根据定义可以得到：假设x的所有子节点用y来循环，那么：dfs(x,pa)=sum(dfs(y,x) for y in (son of x))，注意，因为我们最终需要判断子树总和是否可以被k整除，因此在累加和的时候可以同时对k进行模除，最后判断是否等于0即可，更快
        g = [[] for _ in range(n)] # 首先建图
        for x,y in edges:
            g[x].append(y)
            g[y].append(x)
        
        res = 0
        def dfs(x, pa):
            v = values[x]%k # v用来统计以x为根节点的子树总和
            for y in g[x]:
                if y != pa:
                    v = (v+dfs(y, x))%k
            nonlocal res
            res += (v == 0) # 只要当前子树总和是k的倍数就进行划分
            return v
        dfs(0, -1)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 5
    edges = [[0,2],[1,2],[1,3],[2,4]]
    values = [1,8,1,4,4]
    k = 6
    print(s.maxKDivisibleComponents(n, edges, values, k))
