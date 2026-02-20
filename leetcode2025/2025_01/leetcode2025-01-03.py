from collections import defaultdict

class MyCalendarTwo:

    def __init__(self):
        self.tree = defaultdict(int)
        self.lazy = defaultdict(int)

    def update(self, start, end, l, r, indx, op=1):
        if r<start or end<l:
            # 要更新的区间不在已经区间之内，无须更新
            return
        if start<=l and r<=end:
            # 要更新区间已经在区间之内
            # 此时，需要更新两种统计
            self.tree[indx] += op
            self.lazy[indx] += op
        else:
            # 至此，要更新的区间与已经预订的区间是有交集的
            # 进行二分更新
            mid = (l+r)//2
            self.update(start, end, l, mid, indx*2, op)
            self.update(start, end, mid+1, r, indx*2+1, op)
            # 准备更新当前区间的累计预订量
            self.tree[indx] = self.lazy[indx]+max(self.tree[indx*2], self.tree[indx*2+1])

    def book(self, startTime: int, endTime: int) -> bool:
        self.update(startTime, endTime-1, 0, 10**9, 1, 1)
        # 如果更新以后所有时间的重复预定最大次数超过了两次，那么就需要删除该预定，并返回False
        if self.tree[1]>2:
            # 回退
            self.update(startTime, endTime-1, 0, 10**9, 1, -1)
            return False
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(startTime,endTime)

if __name__ == "__main__":
    mc = MyCalendarTwo()
    booked = [[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]
    for i,j in booked:
        print(mc.book(i, j))
