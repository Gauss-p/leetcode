from typing import List
from functools import cache
from bisect import *

class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        # 首先，如果要求出一个区间内walls中的元素个数，我们需要先将walls从小到大排序，并用二分查找的方式计算。同时，为了在计算的时候保持robots的位置顺序，我们也要将robots中每个元素和对应的最远射程合起来排序
        # 用dfs的思路，每一个机器人都有两个方向，向左或向右，因此我们可以将所有情况全部考虑，取最大值。定义dfs(i,j)表示robots中前i个机器人能够摧毁的最大墙壁数目，其中j表示第i+1个机器人是向左还是向右发射子弹，如果j=1，就说明第i+1个机器人是向左，否则就说明它是向右
        # 在函数中，我们主要处理的是第i个机器人的开枪方式。首先最简单的，如果第i个机器人向左开枪，且位置为x，最大射程为d，那么我们不需要考虑区间[x-d, x]是否和第i+1个机器人的射程有重叠，只需要考虑这个射程是否会打到第i-1个机器人即可，毕竟题目中说了，如果子弹击中一个机器人，它会立即停止。因此我们需要知道第i-1个机器人的位置x2，这样当前的第i个机器人最左也只能射到x2+1的位置(我们不计算射程中机器人的位置，就算有墙和该机器人重叠，在对该机器人的射程判断时计算进去即可)，因此，如果向左，最大的射击范围就是[max(x-d, x2+1), x]，在walls中用二分查找查询位于该区间中的元素个数，加入答案并继续计算前i-1个机器人的情况即可，注意在传入的时候需要将j变成0，表示第i个机器人向左射击
        # 接下来，如果第i个机器人向右开枪，那么此时的射程[x, x+d]有可能和第i+1个机器人的射程重叠，因此我们要根据第i+1个机器人的位置和此时传入的j来确定其射击范围。现已知第i+1个机器人的位置为x2，最远射程为d2，如果此时j=0，说明该机器人向左射击，也就是射击范围为：[x2-d2, x2]，因此我们需要将此时第i个机器人射击范围的右端点和x2-d2-1取最小值。而如果此时j=1，说明该机器人向右射击，射击范围为：[x2, x2+d2]，那么我们需要将右端点和x2-1取最小值以确定最终右端点。最后，用同样的方式求出walls中位于区间内的元素个数，加入答案，继续计算即可
        # 返回值即为向左和向右的最大数目的最大值
        # 由于我们是从后往前遍历的，并且第n个位置的哨兵可以看作向右射击，所以初始参数应该是i=n-1,j=1
        n = len(robots)
        rd = sorted(zip(robots, distance), key = lambda x:x[0]) # 合并列表并排序
        walls.sort()

        @cache
        def dfs(i, j):
            if i<0:
                return 0
            
            x, d = rd[i]
            leftX = x-d
            if i>0: # 只有在左侧有多余机器人的时候进行判断左端点是否会重叠
                leftX = max(leftX, rd[i-1][0]+1)
            left = bisect_left(walls, leftX)
            cur = bisect_right(walls, x)
            resLeft = dfs(i-1, 0)+ (cur-left)

            rightX = x+d
            if i+1<n:
                # 只在右侧有多余机器人的时候进行判断右端点是否会重叠
                x2, d2 = rd[i+1]
                if j == 0:
                    # 根据第i+1个机器人的射击方向来确定最远右端点
                    x2 -= d2
                rightX = min(rightX, x2-1)
            right = bisect_right(walls, rightX)
            cur = bisect_left(walls, x)
            resRight = dfs(i-1, 1)+ (right-cur)

            return max(resLeft, resRight)
        return dfs(n-1, 1)

if __name__ == "__main__":
    s = Solution()
    robots = [4]
    distance = [3]
    walls = [1,10]
    print(s.maxWalls(robots, distance, walls))
