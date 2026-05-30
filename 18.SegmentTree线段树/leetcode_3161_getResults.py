from typing import List
from sortedcontainers import SortedList

class SegmentTree:
    def __init__(self, n):
        # 注意这里的二叉树节点个数是根据底层节点个数n来定的
        self.seg = [0]*(2<<(n).bit_length()) # seg[o]表示：节点o对应的区间中，每一个位置到左侧最近障碍物的距离的最大值

    def update(self, o, l, r, pos, val):
        # 二分建树
        if l == r:
            self.seg[o] = val
            return
        mid = (l+r)//2
        if pos <= mid:
            self.update(2*o, l, mid, pos, val)
        else:
            self.update(2*o+1, mid+1, r, pos, val)
        self.seg[o] = max(self.seg[2*o], self.seg[2*o+1])

    def query(self, o, l, r, endPos):
        if r <= endPos:
            return self.seg[o]
        mid = (l+r)//2
        if endPos <= mid:
            return self.query(2*o, l, mid, endPos)
        return max(self.seg[2*o], self.query(2*o+1, mid+1, r, endPos))

class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        # 分析题目，如果已经知道数轴上所有障碍物的位置，此时要知道在一个区间[0,x]内能否放下长度为sz的物体，则需要快速计算在这个区间内，每个位置离左侧最近障碍物的距离最大值。因此，针对两种操作，代码需要实现以下功能：
        #   1.实时修改一个区间内所有位置离左侧最近障碍物的距离最大值，并进行统计
        #   2.快速计算区间[0,x]内每个位置离左侧最近障碍物的距离最大值
        # 因此可以用「线段树」来实现。

        # 对线段树的每个节点o，记录该节点对应的区间[l,r]中，每个位置离左侧最近障碍物的距离最大值。
        # 如果现在要求[0,x]区间内每个位置离左侧最近障碍物的距离最大值，则可以分以下几种情况讨论(mid=(l+r)//2)：
        #   1.如果r<=x，则说明当前区间已经整个都处在[0,x]区间中，直接返回seg[o]即可
        #   (以下均为r>x的情况，即当前区间可以将待查询区间的末尾部分覆盖)
        #   2.如果x<=mid，则说明当前的左侧子区间可以将待查询区间末尾部分覆盖，那么在左侧子区间继续查询即可
        #   3.如果x>mid，则说明当前的左侧子区间已经全部在待查询区间中，且右侧子区间将待查询区间末尾部分覆盖，因此可以直接将左侧子区间的答案读取，并继续在右侧子区间查询
        # 最终返回所求的所有答案最大值即可

        # 具体实现中，可以用一个有序列表来快速查找一个位置左侧和右侧最近障碍物的距离
        mx = max(q[1] for q in queries)+1
        segT = SegmentTree(mx)

        res = []
        stl = SortedList([0, mx])
        for q in queries:
            cur = q[1]
            indx = stl.bisect_left(cur)-1
            pre = stl[indx]
            if q[0] == 1:
                nxt = stl[indx+1]
                stl.add(cur)
                # 新插入的障碍物将原先区间[pre,nxt]拆成两部分，需要分别更新
                segT.update(1, 0, mx-1, nxt, nxt-cur)
                segT.update(1, 0, mx-1, cur, cur-pre)
            else:
                length = max(segT.query(1, 0, mx-1, pre), cur-pre)
                res.append(length >= q[2])
        return res

if __name__ == "__main__":
    s = Solution()
    queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]
    print(s.getResults(queries))
