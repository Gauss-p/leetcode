from typing import List

class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        # 将所有的分割都加入同一个列表进行排序，用贪心的思路，先切开销最大的
        # 在加入列表的过程中，我们要在每一个数值之后带上一个标志，横向为'h'，纵向为'v'
        # 每次统计已经切出来的横向份数和纵向份数
        tot = []
        for i in horizontalCut:
            tot.append((i, 'h'))
        for i in verticalCut:
            tot.append((i, 'v'))
        tot.sort(key = lambda x:-x[0])
        hPieces, vPieces = 1, 1
        res = 0
        for i, t in tot:
            if t == 'h':
                res += i*vPieces
                hPieces += 1
            else:
                res += i*hPieces
                vPieces += 1

        return res

if __name__ == "__main__":
    s = Solution()
    m, n = 3, 2
    horizontalCut, verticalCut = [1,3], [5]
    print(s.minimumCost(m, n, horizontalCut, verticalCut))
