class MyCalendar:

    def __init__(self):
        # 定义tree用来存储那些有交集，无法预定的区间
        # 定义lazy用来存储那些已经预定的区间
        self.tree = set()
        self.lazy = set()

    def query(self, start, end, l, r, indx):
        # 该函数仅用来返回待查询[start,end]是否已经被预定，被预定了返回true，否则返回false
        # 因此，在主函数中先调用该函数进行查询时，如果返回结果为true，就说明无法预定，主函数应返回false
        # 在函数的变量中，l和r表示索引indx对应的区间
        # 如果区间[l,r]已经和待查询区间没有交集，那么就不需要再继续查找，返回False
        if r<start or end<l:
            return False
        # 如果区间[l,r]和待查询区间有交集，并且[l,r]已经被预定了，说明待查询区间已经被预定，返回True
        if indx in self.lazy:
            return True
        # 如果区间[l,r]在待查询区间内部，并且属于那些和预定区间有交集的区间，那么说明待查询区间有部分已经被预定，返回True，否则返回False
        if start <= l and r <= end:
            return indx in self.tree
        # 继续二分查找
        mid = (l+r)//2
        return self.query(start, end, l, mid, indx*2) or self.query(start, end, mid+1, r, indx*2+1)

    def update(self, start, end, l, r, indx):
        # 该函数用来更新线段树，即加入一个新的区间
        if r<start or end<l:
            # 没有交集
            return
        if start <= l and r <= end:
            # 待标记区间包含了[l,r]，就将indx加入两个集合中
            self.tree.add(indx)
            self.lazy.add(indx)
        else:
            # 待标记区间和[l,r]有交集
            mid = (l+r)//2
            self.update(start, end, l, mid, indx*2)
            self.update(start, end, mid+1, r, indx*2+1)
            # 只要有交集，这段区间就不能被再订，所以需要在tree中加入该段区间对应的标记
            # 但这里要注意，这只是说当前查询的区间无法预订，真正被预订的区间段还需要进一步地判断
            self.tree.add(indx)
            if indx*2 in self.lazy and indx*2+1 in self.lazy:
                # 如果左子区间和右子区间都被预定，那么父区间一定被预定
                self.lazy.add(indx)

    def book(self, startTime: int, endTime: int) -> bool:
        # 首先判断区间是否会产生重复预定
        if self.query(startTime, endTime-1, 0, 10**9, 1):
            return False
        # 然后更新线段树
        self.update(startTime, endTime-1, 0, 10**9, 1)
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)

if __name__ == "__main__":
    s = MyCalendar()
    booked = [[10,20],[15,25],[20,30]]
    for b in booked:
        print(s.book(b[0], b[1]))
