# https://leetcode.cn/problems/fruits-into-baskets-iii/description/
# 3479. 水果成篮 III

from typing import List

# 由于题目中要求我们对于每一个水果求出当前剩余篮子中最左侧能够装得下它的编号，因此，为了减少我们查找的次数，可以用线段树的思路，用二叉树的方式将整个数组不断分成两半，缩减规模，直到找到某个叶子节点符合要求，这样，每一次查询的次数只有O(log(n))。但是面对一个线段时，我们怎样快速知道这个线段中是否有我们需要的大于等于给出元素的值呢？因此，问题就转化称了，给出一个区间，我们如何知道剩余篮子中每一段的容量最大值？
# 这里就可以用线段树来维护了，将basket数组中的所有元素按照二叉树的顺序排列起来，那么对于每一个节点编号o的两个子节点就分别是2*o和2*o+1(注意这里为了避免2*0=0的问题，我们的根节点需要从1开始编号)，因此，定义一个列表seg，其中seg[o]表示节点o对应的线段中所有元素的最大值，那么根据线段树的特性，这个线段可以被分成两个部分，一个是2*o对应的，一个是2*o+1对应的，因此可以知道：seg[o]=max(seg[2*o], seg[2*o+1])
# 接下来，我们需要建树，也就是在初始化的时候根据给出的basket列表进行建线段树。定义build函数，其中build(c,o,l,r)表示：根据原数组c，从根节点o开始，对于原数组中区间[l,r]的元素初始化seg[o]的值。因此我们可以知道，在初始化的时候就需要传入build(basket, 1, 0, n-1)。接下来我们需要递归计算所有线段的最大值，因此我们还需要递归基。注意到每次传入的[l,r]有可能相等，而相等的时候就意味着此时我们只需对一个数字进行初始化，故可以直接将seg[o]置为c[l]。在递归的时候，只需将[l,r]区间平均分称两半，分别传入build进行计算即可
# 之后，针对该题目，我们还需要有一个查询和更新的函数，也就是每一次从整个数组开始查询，不断寻找当前节点的子节点中是否有大于等于给出值的元素，如果找到左右端点相等，就说明我们已经找到目标节点，返回节点在basket中的编号即可，但是注意，这里为了保证之后不重复用一个节点，还需要将seg中该节点的值置为-1。而如果没有找到符合要求的点，返回-1即可

class SegmentTree:
    def __init__(self, c):
        n = len(c)
        # 注意这里的二叉树节点个数是根据底层节点个数n来定的
        self.seg = [0]*(2<<(n-1).bit_length())
        self.build(c, 1, 0, n-1)

    def maintain(self, o):
        # 更新seg[o]的值
        self.seg[o] = max(self.seg[2*o], self.seg[2*o+1])

    def build(self, c, o, l, r):
        # 二分建树
        if l == r:
            self.seg[o] = c[l]
            return
        mid = (l+r)//2
        self.build(c, 2*o, l, mid)
        self.build(c, 2*o+1, mid+1, r)
        self.maintain(o)

    def find_first_and_update(self, o, l, r, x):
        # 查找并标记给出的x
        if self.seg[o]<x:
            return -1
        if l == r:
            self.seg[o] = -1
            return l
        mid = (l+r)//2
        # 为了保证题目要求的“最左侧”，我们需要先找左子树，后找右子树
        i = self.find_first_and_update(2*o, l, mid, x)
        if i<0:
            i = self.find_first_and_update(2*o+1, mid+1, r, x)
        self.maintain(o) # 最后记得更新
        return i

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        segT = SegmentTree(baskets)
        n = len(baskets)
        res = len(fruits)
        for x in fruits:
            if segT.find_first_and_update(1, 0, n-1, x) >= 0:
                # 只要找到了basket中的索引，就说明当前水果可以放下，将答案减1
                res -= 1
        return res

if __name__ == "__main__":
    s = Solution()
    fruits = [4,2,5]
    baskets = [3,5,4]
    print(s.numOfUnplacedFruits(fruits, baskets))
