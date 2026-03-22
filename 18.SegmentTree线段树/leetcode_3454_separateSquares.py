from typing import List

class Node:
    def __init__(self):
        self.l = self.r = 0
        self.cnt = self.length = 0
    
class SegmentTree:
    def __init__(self, nums):
        n = len(nums)-1
        self.nums = nums
        self.tr = [Node() for _ in range(4*n)]
        self.build(1, 0, n-1)
    
    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l != r:
            mid = (l+r)//2
            self.build(u*2, l, mid)
            self.build(u*2+1, mid+1, r)
    
    def modify(self, u, l, r, k):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            self.tr[u].cnt += k
        
        else:
            mid = (self.tr[u].l + self.tr[u].r)//2
            if l<=mid:
                self.modify(u*2, l, r, k)
            if r>mid:
                self.modify(u*2+1, l, r, k)
        self.pushup(u)
    

    def pushup(self, u):
        if self.tr[u].cnt != 0:
            self.tr[u].length = self.nums[self.tr[u].r+1]-self.nums[self.tr[u].l]

        elif self.tr[u].l == self.tr[u].r:
            self.tr[u].length = 0
        
        else:
            self.tr[u].length = self.tr[u*2].length+self.tr[u*2+1].length

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        event = []
        st = set()
        for x,y,l in squares:
            x2, y2 = x+l, y+l
            event.append((y, x, x2, 1))
            event.append((y2, x, x2, -1))
            st.update([x,x2])
        
        event.sort()
        xst = sorted(st)
        d = {x:i for i,x in enumerate(xst)}

        SegT = SegmentTree(xst)
        tot = 0
        y0 = 0
        for y,x1,x2,k in event:
            tot += (y-y0)*SegT.tr[1].length
            SegT.modify(1, d[x1], d[x2]-1, k)
            y0 = y

        target = tot/2
        area = 0
        SegT = SegmentTree(xst)
        y0 = 0
        for y,x1,x2,k in event:
            cur = (y-y0)*SegT.tr[1].length
            if area+cur >= target:
                return y0+(target-area)/SegT.tr[1].length
            area += cur
            SegT.modify(1, d[x1], d[x2]-1, k)
            y0 = y

        return 0

if __name__ == "__main__":
    s = Solution()
    squares = [[0,0,1],[2,2,1]]
    print(s.separateSquares(squares))
