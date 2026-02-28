from typing import List
from functools import cache

class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        # 可以这样想，从每一个1的位置出发，然后用dfs的方式遍历每一条路径，求出最长的，最后对于每一个1位置对应的最长路径长度求一个最大值即为答案了。注意到题目中提到一个路径中最多只能有一次顺时针90度转向，因此，在dfs中，我们需要一个变量来记录之前的路径中是否有过转弯，以及当前的方向是朝向何处。所以我们可以这样想，用一个列表保存四个方向，并按照顺时针方向排列，即：右下，左下，左上，右上，这样我们只需要维护一个数字，代表在方向列表中的索引，即可实现对方向的确定，而转弯则可以直接通过将索引加1模除4来得到新的索引即可
        # 同时由于序列模式要求为：1，2，0，2，0···，所以从第2个数字开始，我们就可以通过用2减去上一次的数值来确定当前应该要有的数字，这样，可以方便我们确认每一个点的数值是否符合要求。
        # 最后考虑递归基，如果当前传入的点已经超出了grid的索引范围或当前位置对应的值不符合给出的值，就直接返回0，否则需要考虑转向或不转向两种情况，注意，转向的前提是之前没有转过。然后在每次返回答案的时候记住要加上当前这个数字对应的长度1
        m, n = len(grid), len(grid[0])
        dirs = [(1,1), (1,-1), (-1,-1), (-1,1)]

        @cache
        def dfs(x, y, curDir, is_turned, target):
            if x<0 or x>=m or y<0 or y>=n or grid[x][y] != target:
                return 0

            nextTarget = 2 if target==1 else 2-target

            nx, ny = x+dirs[curDir][0], y+dirs[curDir][1]
            ans = dfs(nx, ny, curDir, is_turned, nextTarget)

            if not is_turned:
                nextDir = (curDir+1)%4
                nx, ny = x+dirs[nextDir][0], y+dirs[nextDir][1]
                ans = max(ans, dfs(nx, ny, nextDir, not is_turned, nextTarget))
            return ans+1

        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for d in range(4):
                        # 每一个是1的点都需要从4个方向出发判断
                        res = max(res, dfs(i, j, d, False, 1))
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
    print(s.lenOfVDiagonal(grid))
