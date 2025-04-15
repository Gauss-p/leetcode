from typing import List
from sortedcontainers import SortedList

class TreeArray:
    # 树状列表，定义一个列表tree，其中每一个值对应原列表中某一段的和，它的组成方式是这样的，索引从1开始，如果我们要求[1,i]的原数组之和，那么它可以用i的二进制位上为1的那些位置进行分割，从1开始，同时从i二进制的最高位开始，如果(i>>x)&1=1，那么答案就要加上一个tree[a+2**x]，其中a的值为上一个区间的结尾位置
    # 举个例子，如果原列表长度为4
    # |-----------------s[4]------------------------|
    #            /                     /         |
    # |--------s[2]---------|         /          |
    #        /        |              /           |
    # |--s[1]--|      |         |--s[3]--|       |
    #      /          |              |           |
    #   base[1]     base[2]      base[3]       base[4]
    # 那么我们可以根据这个定义，设计一个更新函数和一个求前缀和的函数(此处前缀和的原列表base中的base[i]应该指的是数字i在NewNums2中的出现次数)，两者思路大致相同，不过更新的函数是依次向后更新，求前缀和只需根据定义依次向前更新即可
    def __init__(self, n):
        self.tree = [0]*(n+1)

    def update(self, pos, val):
        while pos<len(self.tree):
            self.tree[pos] += val
            pos += (pos & -pos)
    
    def preSum(self, pos):
        res = 0
        while pos>0:
            res += self.tree[pos]
            pos -= (pos & -pos)
        return res

class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        # 思路如下，为了求nums1和nums2中的相同顺序三元组的数量，可以考虑将nums1中的数字进行映射，使得nums1变成一个单调递增数组，同时将同样的映射放在nums2上，得到一个新数组NewNums2。举个例子，如果nums1=[2,0,1,3]，nums2=[0,1,2,3]，那么通过映射，nums1变成了[0,1,2,3]，NewNums2则为[1,2,0,3]
        # 这时，由于在刚才的映射中我们没有改变数组中数字顺序，所以如果现在nums1和nums2中的某两个三元组顺序相同，那么在原来它们的顺序也同样相同，因此，问题变成了在NewNums2中找到所有单调递增的三元组数量，在上面了例子中就相当于求[1,2,0,3]中单调递增的三元组数量
        # 在一个数组arr中，如果索引(i,j,k)对应的三元组(arr[i],arr[j],arr[k])是单调递增的，那么arr[i]<arr[j]，arr[k]>arr[j]，所以对于一个数字arr[j]，如果知道它左边的小于arr[j]的数字数量less，就可以知道它右边的大于arr[j]的数字数量。因为左边一共有j个数字，所以左边大于arr[j]的数字数量就是j-less，又因为数组中一共有n-j-1个数字大于arr[j]，所以j右边大于arr[j]的数字数量就是(n-j-1-(j-less))，将其与less相乘即可得到以arr[j]为中间元素的单调递增三元组数量
        # 下面有两种方法，第一种，每次用SortedList中的bisect_left求出当前数字arr[i]的所处位置，它的索引即为less，然后根据上面的公式累加答案，最后将当前值加入SortedList中即可
        # 第二种，用树状列表，利用树状列表的增加和求和方法快速求出less的值进行计算即可
        n = len(nums1)
        funx = [0]*n
        for i in range(n):
            funx[nums1[i]] = i

        res = 0
        # sl = [0]*(n+1)
        sl = TreeArray(n)
        for i in range(n):
            v = nums2[i]
            y = funx[v]
            # less = sum(sl[:y+1])
            less = sl.preSum(y)
            res += less*(n-y-1-(i-less))
            # sl[y+1] = 1
            sl.update(y+1, 1)
        return res

        # n = len(nums1)
        # funx = [0]*n
        # for i in range(n):
        #     funx[nums1[i]] = i

        # res = 0
        # sl = SortedList()
        # for i in range(n):
        #     v = nums2[i]
        #     y = funx[v]
        #     less = sl.bisect_left(y)
        #     print(sl, y, less)
        #     res += less*(n-y-1-(i-less))
        #     sl.add(y)
        # return res

if __name__ == "__main__":
    s = Solution()
    nums1 = [2,0,1,3]
    nums2 = [0,1,2,3]
    print(s.goodTriplets(nums1, nums2))
