from typing import List

class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        def calc(l1, r1, l2, r2):
            length = 0
            if l1 <= l2 <= r1 <= r2:
                length = r1-l2
            elif l1 <= l2 <= r2 <= r1:
                length = r2-l2
            return length

        n = len(bottomLeft)
        res = 0
        for i in range(n):
            bl1 = bottomLeft[i]
            tr1 = topRight[i]
            for j in range(i+1, n):
                bl2 = bottomLeft[j]
                tr2 = topRight[j]
                
                x_length = max(calc(bl1[0], tr1[0], bl2[0], tr2[0]), 
                               calc(bl2[0], tr2[0], bl1[0], tr1[0]))
                
                y_length = max(calc(bl1[1], tr1[1], bl2[1], tr2[1]),
                               calc(bl2[1], tr2[1], bl1[1], tr1[1]))

                edge = min(x_length, y_length)
                res = max(res, edge*edge)
        return res

if __name__ == "__main__":
    s = Solution()
    bottomLeft = [[1,1],[2,2],[3,1]]
    topRight = [[3,3],[4,4],[6,6]]
    print(s.largestSquareArea(bottomLeft, topRight))
