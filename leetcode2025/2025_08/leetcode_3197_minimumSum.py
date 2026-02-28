from typing import List

class Solution:
    def minimumSum(self, grid: List[List[int]]) -> int:
        # 暴力，将一个矩形分成三个部分，在每一个小矩形中找出包含其中所有1的最小矩形面积，然后求最小总面积即可
        # 分一个矩形有六种分法：
        # 1.上中下
        # 2.左中右
        # 3.先分上下，在下面部分中分左右
        # 4.先分上下，在上面部分中分左右
        # 5.先分左右，在左边部分中分上下
        # 6.先分左右，在右边部分中分上下
        # 求最小面积直接用上一题的代码即可
        def minimumArea(i1, j1, i2, j2):
            # 直接暴力找到所有1中最上面、最下面、最左边、最右边的位置，即可以确定最小长方形的大小
            myMax = lambda x,y : x if x>y else y
            myMin = lambda x,y : x if x<y else y
            m, n = len(grid), len(grid[0])
            up, down, left, right = float("inf"), 0, float("inf"), 0
            for i in range(i1, i2+1):
                for j in range(j1, j2+1):
                    if grid[i][j] == 1:
                        up = myMin(up, i)
                        down = myMax(down, i)
                        left = myMin(left, j)
                        right = myMax(right, j)
            return (down-up+1)*(right-left+1)

        res = float("inf")
        m, n = len(grid), len(grid[0])
        for i1 in range(m-2):
            for i2 in range(i1+1, m-1):
                # 上中下
                s1 = minimumArea(0, 0, i1, n-1)
                s2 = minimumArea(i1+1, 0, i2, n-1)
                s3 = minimumArea(i2+1, 0, m-1, n-1)
                res = min(res, s1+s2+s3)

        for j1 in range(n-2):
            for j2 in range(j1+1, n-1):
                # 左中右
                s1 = minimumArea(0, 0, m-1, j1)
                s2 = minimumArea(0, j1+1, m-1, j2)
                s3 = minimumArea(0, j2+1, m-1, n-1)
                res = min(res, s1+s2+s3)

        for i in range(m-1):
            for j in range(n-1):
                # 上-左右
                s1 = minimumArea(0, 0, i, n-1)
                s2 = minimumArea(i+1, 0, m-1, j)
                s3 = minimumArea(i+1, j+1, m-1, n-1)
                res = min(res, s1+s2+s3)

                # 左右-下
                s1 = minimumArea(0, 0, i, j)
                s2 = minimumArea(0, j+1, i, n-1)
                s3 = minimumArea(i+1, 0, m-1, n-1)
                res = min(res, s1+s2+s3)

                # 上下-右
                s1 = minimumArea(0, 0, i, j)
                s2 = minimumArea(i+1, 0, m-1, j)
                s3 = minimumArea(0, j+1, m-1, n-1)
                res = min(res, s1+s2+s3)

                # 左-上下
                s1 = minimumArea(0, 0, m-1, j)
                s2 = minimumArea(0, j+1, i, n-1)
                s3 = minimumArea(i, j+1, m-1, n-1)
                res = min(res, s1+s2+s3)

        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[1,0,1],[1,1,1]]
    print(s.minimumSum(grid))
