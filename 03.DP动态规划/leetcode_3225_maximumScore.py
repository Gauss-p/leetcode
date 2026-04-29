from typing import List

class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        # 分析题目，如果有多个列都有部分被涂成黑色，那么这几个连续的列中涂黑色部分一定满足以下条件：
        #   1.都是山峰，没有山谷(即黑色部分长度从左到右先单增后单减)
        #   2.山峰的顶点一定到达最大长度(即黑色部分最大长度是整一列)
        #   3.如果有一列完全空白，那么它两侧两列一定完全涂黑
        # 其证明如下：对于1，只要有山谷，那么将山谷对应的最短的那一列整个清空，就会使总和增加；对于2，只要山峰顶点没有到最后一行，那么就将它延长到最后一行，即可使总和增加；对于3，如果存在一列完全空白，但右侧一列并没有完全涂黑，那么由2可知，右侧列的右边一定会有一个山峰，那么将右侧一列清空，即可在总和中增加原先右侧列被黑色覆盖的位置
        # 接下来考虑用动态规划的方法计算可以获得的最大分数：
        #   1.定义dpInc[i][k]表示：在前i列中，第i列涂k个格子，且到i列时黑色格子数量呈增加趋势时，能够获得的最大分数；
        #   2.定义dpDec[i][k]表示：在前i列中，第i列涂k个格子，且到i列时黑色格子数量呈减少趋势时，能够获得的最大分数。
        # 之后考虑状态转移方程，如果第i-1列涂了j个格子，第i列涂了k个格子，那么：
        #   1.当j<=k时，新增的分数就是第i-1列中第j行到第k行的数字总和
        #   2.当j>=k时，新增的分数就是第i列中第k行到第j行的数字总和
        # 因此根据上述递推关系可以写出如下递推关系式：
        #   1.当j<=k时，dpInc[i][k] = dpInc[i-1][j]+sum(dp[i-1][indx] for indx in range(j,k))
        #   2.当j>=k时，dpDec[i][k] = dpDec[i-1][j]+sum(dp[i][indx] for indx in range(k,j))
        # 最后考虑极端情况的转换，当一个列涂0个格子的时候，如果此时它呈上升趋势，那么它可以从上一列涂0个格子且呈下降趋势的位置转移过来；当一个列涂满格子且呈上升趋势的时候，它同样可以从上一列涂0个格子且呈下降趋势的位置转移过来；当一个列涂满格子且呈下降趋势时，它则可以和「当前列涂满格子且呈上升趋势」等价
        n = len(grid)
        preSum = [[0]*(n+1) for _ in range(n+1)]
        for i in range(n):
            for j in range(n):
                preSum[i+1][j+1] = grid[j][i]
        
        for i in range(n):
            for j in range(n):
                preSum[i+1][j+1] += preSum[i+1][j]

        dpInc = [0]*(n+1)
        dpDec = [-float("inf")]*(n+1)
        for i in range(1, n+1):
            ndpInc = [0]*(n+1)
            ndpDec = [-float("inf")]*(n+1)
            for j in range(n+1):
                for k in range(j, n+1):
                    ndpInc[k] = max(ndpInc[k], dpInc[j]+preSum[i-1][k]-preSum[i-1][j])
                for k in range(j+1):
                    ndpDec[k] = max(ndpDec[k], dpDec[j]+preSum[i][j]-preSum[i][k])
                
            ndpInc[0] = max(ndpInc[0], dpDec[0])
            ndpInc[n] = max(ndpInc[n], dpDec[0])
            ndpDec[n] = max(ndpDec[n], ndpInc[n])

            dpInc = ndpInc
            dpDec = ndpDec
        
        return max(max(dpInc), max(dpDec))

if __name__ == "__main__":
    s = Solution()
    grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]
    print(s.maximumScore(grid))
