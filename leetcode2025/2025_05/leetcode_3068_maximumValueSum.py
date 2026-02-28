from typing import List

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        # 定义动态规划数组f[x]表示子树x的除去x的最大价值和，并且我们定义f[x][0]表示x操作偶数次时，子树x的除去x的最大价值和，同时定义f[x][1]表示x操作奇数次时，子树x的除去x的最大价值和
        # 那么对于一个根节点x，我们考虑它的所有孩子，用y在它的孩子列表中遍历。那么(x,y)就是一条边，对于这条边我们有两种情况，即操作或不操作。
        # 如果操作，我们先计算以y为根节点的子树的和，那么根据定义，可以知道，如果原先对y操作了偶数次，则子树y的除去y的最大价值和就是f[y][0]，这时我们又操作了一次，变成了奇数次，那么对于整个子树的和就相当于用f[y][0]+(nums[y]^k)，同理，如果我们原先对y操作了奇数次，那么子树y的除去y的最大价值和就是f[y][1]，这时又操作了一次，变成了偶数次，整个子树的和就变成了f[y][1]+nums[y]，至此我们可以得到以y为根节点的子树的最大和，即max(f[y][0]+(nums[y]^k), f[y][1]+nums[y])，为了方便，我们将刚才的值用r1表示，接下来我们需要计算f[x][0]和f[x][1]，这时，因为当前是需要对x进行操作的，所以操作之后对x的操作总数的奇偶性会发生变化，即f[x][0]=f[x][1]+r1，f[x][1]=f[x][0]+r1，需要注意的是，这两者需要同时变化而非有先后顺序
        # 反之，如果不操作，根据定义，这时对x和y的总操作次数的奇偶性都不会变化，那么子树y的最大价值和就是r0=max(f[y][0]+nums[y], f[y][1]+(nums[y]^k))，同时，对f[x][0]和f[x][1]的更新就直接用f[x][0]=f[x][0]+r0，f[x][1]=f[x][1]+r0即可，这里奇偶性没有改变
        # 整体上我们可以用DFS来实现，定义dfs(x,pa)计算以x为根节点的子树的最大和，最终返回两个值，第一个是对pa操作偶数次的子树最大和，第二个是对pa操作奇数次的子树最大和，因此最终返回值只能是dfs(0, -1)[0]，因为-1节点不可能操作1次及以上，用f0表示f[x][0]，用f1表示f[x][1]，那么最终返回值就是第一个：max(f0+nums[x], f1+(nums[x]^k))，第二个：max(f0+(nums[x]^k), f1+nums[x])，也就是第一个不操作nums[x]，第二个操作nums[x]
        n = len(nums)
        g = [[] for _ in range(n)]
        for a,b in edges:
            g[a].append(b)
            g[b].append(a)

        def dfs(x, p):
            f0, f1 = 0, -float("inf") # 初始化，为了保证
            for y in g[x]:
                if y == p:
                    continue
                r0, r1 = dfs(y, x)
                f0, f1 = max(f0+r0, f1+r1), max(f1+r0, f0+r1)
            return (max(f0+nums[x], f1+(nums[x]^k)), max(f0+(nums[x]^k), f1+nums[x]))

        return dfs(0, -1)[0]

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,1]
    k = 3
    edges = [[0,1],[0,2]]
    print(s.maximumValueSum(nums, k, edges))
