from typing import List

class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        # 直接暴力找到所有1中最上面、最下面、最左边、最右边的位置，即可以确定最小长方形的大小
        myMax = lambda x,y : x if x>y else y
        myMin = lambda x,y : x if x<y else y
        m, n = len(grid), len(grid[0])
        up, down, left, right = float("inf"), 0, float("inf"), 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    up = myMin(up, i)
                    down = myMax(down, i)
                    left = myMin(left, j)
                    right = myMax(right, j)
        return (down-up+1)*(right-left+1)

if __name__ == "__main__":
    s = Solution()
    grid = [[0,1,0],[1,0,1]]
    print(s.minimumArea(grid))
