from typing import List
from collections import defaultdict
from sortedcontainers import SortedList

class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        # 首先我们新建一个矩阵用来表示城市中每一个位置，接下来，循环每一个行，对于行中满足以下条件的位置在矩阵中相应位置加1：1.该位置有建筑；2.该位置不是行中第一个或最后一个建筑。然后循环每一个列，对于列中满足以下条件的位置在矩阵中相应位置加1：1.该位置有建筑；2.该位置不是列中第一个或最后一个建筑
        # 可以发现，在第一个操作中我们标记了所有的左右两个方向有建筑的位置，在第二个操作中我们标记了所有的上下两个方向有建筑的位置，这样，我们只需要找出两次都被标记的位置数量就是答案，而由于我们在两次操作中都有加1，因此最后统计新矩阵中值为2的位置数量即可
        rows = [SortedList() for _ in range(n)]
        cols = [SortedList() for _ in range(n)]
        for x,y in buildings:
            rows[x-1].add(y-1)
            cols[y-1].add(x-1)
        
        res = 0
        newGrid = defaultdict(int) # 防止空间占用过大，用字典代替新矩阵
        for i in range(n):
            for j in rows[i][1:len(rows[i])-1]:
                newGrid[(i,j)] += 1
        for j in range(n):
            for i in cols[j][1:len(cols[j])-1]:
                newGrid[(i,j)] += 1
                if newGrid[(i,j)] == 2:
                    res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    n = 3
    buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
    print(s.countCoveredBuildings(n, buildings))
