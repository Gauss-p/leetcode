from typing import List

class Solution:
    def organizeChessboard(self, pieces: List[List[int]]) -> int:
        # 对于所有的棋子，我们有两种排列方式，第一种是将它们全部排列到一行连续且平行于x轴，第二种是将它们全部排列到一列且平行于y轴，在下面我们先考虑如何将它们排列到一行且平行于x轴，因为两种情况其实是等价的
        # 如果要将它们排列到一行，就需要将它们所有纵坐标变得相等，因此我们将所有点的纵坐标先列出来，那么我们接下来要做的就是将这些数字全部增减至同一个数字，并且总操作次数要最少。因此可以想到中位数，我们只需将这些纵坐标的中位数找出来，那么将所有值变成该数字的总操作数量就最少。因此我们只需排序整个数组，取出最中间的元素，然后求出所有元素和该数字的差值绝对值之和，就可以找到将这些点移动到同一行所需的最小曼哈顿距离
        # 接下来，在解决了一行的问题后，剩下的问题就变成了应如何排列才能使·将一行中所有点移动至连续状态的总曼哈顿距离·的值最小。很显然，我们需要在保证先后顺序不变的前提下进行移动，也就是原先横坐标最小的点移动后也应当处在横坐标最小的位置。因此，假设原先所有点的横坐标分别是[x1, x2,..., xn]，并且x1在移动后变成了c，那么移动后的坐标就是[c, c+1,..., c+n-1]，所以可以发现，如果将先后两个列表中的各个值分别减去其对应的索引，原先的横坐标就变成[x1, x2-1,..., xn-n+1]，移动后的横坐标全部都变成了c。这样一来，问题就变成了：如何取c才能使[x1, x2-1,..., xn-n+1]这些值移动到c的曼哈顿距离之和最小？也就等同于上面处理的同一行的问题了。因此我们只需将[x1, x2-1,..., xn-n+1]这些值排序后取中位数，这个中位数就是要求的c，然后分别计算它们与中位数的距离之和，即可得到我们需要的值
        # 在具体实现中，我们可以定义一个函数allToOneValue，用来计算怎样才能使一个列表中的所有值移动到同一个位置的曼哈顿距离之和最小，同时定义一个函数allToOneLine，用来计算怎样才能使一个列表中的所有值排成连续的一列的曼哈顿距离之和最小。因此，计算排成同一行且连续的最小曼哈顿距离之和就可以在两个函数中分别传入所有点的纵坐标列表，和它们的横坐标列表，并将返回值相加即可。排成同一列且连续也是同理，只需将横纵坐标列表的传入顺序交换一下即可
        n = len(pieces)
        def allToOneValue(lst):
            lst.sort() # 排序，方便取中位数
            ans = 0
            for i in range(n):
                ans += abs(lst[i]-lst[n//2])
            return ans

        def allToOneLine(lst):
            lst.sort() # 按顺序排列，原先横坐标最小的点最后也应横坐标最小
            for i in range(n): # 转换列表，将所有值都分别减去它们的索引
                lst[i] -= i
            lst.sort() # 排序，方便取中位数
            ans = 0
            for i in range(n):
                ans += abs(lst[i]-lst[n//2])
            return ans

        arrX, arrY = [], []
        for x, y in pieces: # 取出所有点的横纵坐标
            arrX.append(x)
            arrY.append(y)

        modNum = 1_000_000_007
        res1 = (allToOneValue(arrX)+allToOneLine(arrY.copy()))%modNum # 排成一列
        res2 = (allToOneValue(arrY)+allToOneLine(arrX.copy()))%modNum # 排成一行
        return min(res1, res2)

if __name__ == "__main__":
    s = Solution()
    pieces = [[0,0],[0,1]]
    print(s.organizeChessboard(pieces))
