from sortedcontainers import SortedList

class ExamRoom:
    def __init__(self, n: int):
        # 为了计算方便，我们可以在考场的左右两端分别加上-1和n两个哨兵，这样，在计算某个区间中的最大距离的时候就可以区分出区间在考场的最左端和最右端的情况
        # 定义dist函数，用来计算区间内和两端学生的最大距离，如果该区间在整个考场的最左端或者最右端，那么在该区间中的最大距离就是区间大小减1，否则就是区间大小的一半。这个函数可以用来在有序列表中实现自定义排序
        # 因为题目要求每次必须坐在和两边的人距离最大的位置上，所以我们可以将每个区间按照dist函数计算出来的数值从大到小排序，又因为题目要求每次都要坐在下标最小的地方，所以如果两个区间用dist计算出来的数值相等，就按左端点位置从小到大排序，在python的SortedList中可以自动实现这一要求
        # 又因为题目中会出现有人离开的情况，我们发现，如果有人离开，那么就会有两个区间合并为一个大区间，所以我们需要分别记录一个人的左右两边最近的人的位置，定义两个字典left和right，分别记录每个座位的左右两边最近的人的位置
        # 在初始化的时候，就首先调用add函数加入区间(-1,n)，这就作为我们的初始区间
        def dist(x):
            l, r = x
            if l==-1 or r==n:
                return r-l-1
            return (r-l)>>1
        
        self.n = n
        self.ts = SortedList(key = lambda x:(-dist(x), x[0])) # 定义有序列表
        self.left = {} # 每个人的左右两边最近的人的位置
        self.right = {}
        self.add((-1, n)) # 初始区间

    def add(self, s):
        # 每次加入某个区间的时候，我们首先将该区间加入有序列表中，其次在left和right中记录如下信息：s[1]左边最近的人的位置是s[0]，s[0]右边最近的人是s[1]
        self.ts.add(s)
        self.left[s[1]] = s[0]
        self.right[s[0]] = s[1]

    def seat(self) -> int:
        # 找出能够满足最大距离的要求的区间
        space = self.ts[0]
        p = (space[0]+space[1])>>1
        # 解决区间在最左端和最右端的情况
        if space[0] == -1:
            p = 0
        elif space[1] == self.n:
            p = self.n-1
        # 插入一个人，就要将一个区间变成两个，所以删除原来的，加入两个新的
        self.delete(space)
        self.add((space[0], p))
        self.add((p, space[1]))
        return p

    def delete(self, s):
        # 删除区间的时候，首先在有序列表中删除区间，其次在left和right中删除s[1]对应的位置和s[0]对应的位置
        self.ts.remove(s)
        self.left.pop(s[1])
        self.right.pop(s[0])

    def leave(self, p: int) -> None:
        # 有人离开的时候，先删除两个小的区间，再加入一个大的区间
        l, r = self.left[p], self.right[p]
        self.delete((l, p))
        self.delete((p, r))
        self.add((l, r))


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)

if __name__ == "__main__":
    er = ExamRoom(10)
    for i in range(4):
        print(er.seat(), end = " ")
    er.leave(4)
    print(er.seat())
