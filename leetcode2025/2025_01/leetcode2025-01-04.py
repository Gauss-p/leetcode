from collections import defaultdict

class MyCalendarThree:

    def __init__(self):
        self.tree = defaultdict(int)
        self.lazy = defaultdict(int)

    def update(self, start, end, l, r, indx):
        if r<start or end<l:
            # 要更新的区间不在区间之内，无须更新
            return
        if start<=l and r<=end:
            # 要更新区间已经在区间之内，需要更新两种统计
            self.tree[indx] += 1
            self.lazy[indx] += 1
        else:
            # 至此，要更新的区间与已经预订的区间是有交集的，进行二分更新
            mid = (l+r)//2
            self.update(start, end, l, mid, indx*2)
            self.update(start, end, mid+1, r, indx*2+1)
            # 更新当前区间的累计预订量
            self.tree[indx] = self.lazy[indx]+max(self.tree[indx*2], self.tree[indx*2+1])

    def book(self, startTime: int, endTime: int) -> int:
        # 每次更新后返回所有时间段的最大重复预定次数即可
        self.update(startTime, endTime-1, 0, 10**9, 1)
        return self.tree[1]


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)

if __name__ == "__main__":
    mc = MyCalendarThree()
    booked = [[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]
    for b in booked:
        print(mc.book(b[0], b[1]))
