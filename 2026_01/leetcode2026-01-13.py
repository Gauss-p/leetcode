from typing import List

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        n = len(squares)
        sq = []
        for x,y,l in squares:
            sq.append((y, y+l))
        sq.sort()

        def check(mid):
            # 判断mid上方面积和mid下方面积大小关系，如果上大于等于下，那么下降二分查找右端点，否则上升二分查找左端点
            over = 0
            below = 0
            for d,u in sq:
                if u<=mid:
                    below += (u-d)*(u-d)
                elif d>=mid:
                    over += (u-d)*(u-d)
                else:
                    below += (u-d)*(mid-d)
                    over += (u-d)*(u-mid)
            return over <= below
        
        l, r = 0, max(x[1] for x in sq)
        while abs(l-r) > 0.00001:
            mid = (l+r)/2
            if check(mid):
                r = mid
            else:
                l = mid
        return l

if __name__ == "__main__":
    s = Solution()
    squares = [[0,0,1],[2,2,1]]
    print(s.separateSquares(squares))
