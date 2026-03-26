from typing import List

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        # 可以将整个矩阵的分割分成四部分考虑：1.水平分割，在上面部分删除数字；2.水平分割，在下面部分删除数字；3.垂直分割，在左边部分删除数字；4.垂直分割，在右边部分删除数字
        # 注意到通过将矩阵转制或上下颠倒，可以将后三种情况的处理都变为情况1，故现在只考虑情况1的处理
        # 最简单的思路就是：从上往下依次遍历每一行，维护已遍历的所有行中可以删除的数字集合cnt(有的数字因为删除后会导致上半部分不连通，故不能删除)，同时维护已遍历的所有行的数字总和cur。如果遍历到当前行为第i行，那么就表示当前以第i行和第i+1行中间的线作为分界线，分割这个矩阵。记整个矩阵的和为tot，那么下半部分的和就是tot-cur，为了让cur变得和tot-cur相同，需要在上半部分减去cur*2-tot，因此只需要判断cnt中是否存在cur*2-tot即可知道是否可以通过删除一个元素得到等和矩阵分割
        # 不过需要注意的是，在选择元素的时候，当i=0时，不能删除第0行的中间任意一个元素，因为无论删除中间哪个元素都会使得上半部分断开，只能删除第0行两边的元素；同时，当grid只有一列的时候，上半部分的所有元素中只能删除第0行的和第i行的那个，否则都会使上半部分断开
        totSum = sum(sum(r) for r in grid)
        
        def calc(curGrid):
            m, n = len(curGrid), len(curGrid[0])
            cnt = set([0])
            cur = 0
            for i in range(m-1):
                # 将当前行更新到cnt和cur中
                for j in range(n):
                    cur += curGrid[i][j]
                    if i > 0 or j==0 or j==n-1:
                        # 注意，当i=0时只能删除第0行两端的元素
                        cnt.add(curGrid[i][j])

                if n == 1:
                    if cur*2 == totSum or 2*cur-totSum==curGrid[0][0] or 2*cur-totSum==curGrid[i][0]:
                        # 只有一列的时候，只能删除第0行或第i行的元素
                        return True
                    continue

                if cur*2-totSum in cnt:
                    return True
                
                if i == 0:
                    # 第0行中间的元素在这里处理
                    cnt.update(curGrid[0])
            return False
            
        newGrid = list(zip(*grid))
        return calc(grid) or calc(grid[::-1]) or calc(newGrid) or calc(newGrid[::-1])

if __name__ == "__main__":
    s = Solution()
    grid = [[1,4],[2,3]]
    print(s.canPartitionGrid(grid))
