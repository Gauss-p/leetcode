from typing import List

class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        # 注意到题目中要求的从左上到右下的对角线有一个特征：同一条对角线上的每一个点(i,j)的i-j是一个定值。因此我们可以循环i-j的可能值，然后令i从0开始循环到n，分别计算出对应的j，判断j是否超出了索引范围，如果没有，就将它加入一个列表中，从而得到每一条对角线上的所有数字，当然，也可以根据j=i-curDiff，按照j的索引范围确定i的最小和最大索引，直接循环，这样可以减少判断次数
        # 接下来需要对每一条对角线进行排序。可以发现，右上角的矩阵中i-j的值是小于0的，左下角的矩阵中i-j的值是大于等于0的，因此可以根据当前的差值正负号来判断应该按照非单减还是非单增排序。
        # 最后，在将所有对角线上的数字排序完成以后，重新将所有对角线上的数字填入grid中对应位置即可
        n = len(grid)
        lst = []
        for curDiff in range(-n+1, n):
            lst.append([])
            # y = x-curDiff
            # x-curDiff >= 0 --> x >= curDiff
            # x-curDiff < n  --> x < n+curDiff
            # curDiff <= x < n+curDiff
            # 0 <= x < n
            # so, max(0, curDiff) <= x < min(n+curDiff, n)
            for x in range(max(curDiff, 0), min(n+curDiff, n)):
                curY = x-curDiff
                lst[-1].append(grid[x][curY])
            if curDiff < 0:
                # 属于右上角矩阵，按非单增排序
                lst[-1].sort()
            else:
                # 属于左下角矩阵，按非单减排序
                lst[-1].sort(reverse = True)

        for curDiff in range(-n+1, n):
            for x in range(max(curDiff, 0), min(n+curDiff, n)):
                curY = x-curDiff
                grid[x][curY] = lst[curDiff+n-1][0]
                lst[curDiff+n-1].pop(0)
        
        return grid

if __name__ == "__main__":
    s = Solution()
    grid = [[1,7,3],[9,8,2],[4,5,6]]
    print(s.sortMatrix(grid))
