# https://leetcode.cn/problems/maximum-total-subarray-value-ii/
# 3691.最大子数组总值II

from typing import List
from heapq import *

# 这道题目需要我们快速求出一个区间内的最大值和最小值之差，因此可以使用稀疏列表来解决这类问题。
# 稀疏列表和FenwickTree相似，但是其中稀疏列表中存储的值是：以1,2,4,8,16...为子数组长度，同时对于每一个长度都从每一个点作为起点进行计算子数组对应的值。例如当传入的二元计算函数是max时，存储的就是长度分别为1,2,4...的所有子数组的最大值。这样就方便计算任意一个子数组对应的值
# 而FenwickTree是：对于每一个点，将其作为一个子数组的末尾，存储一个子数组的总和，这样就方便计算一个子数组中所有数字的总和，可以将其从头到尾累加数组中对应的和即可
# 对比来看，稀疏矩阵更适合本题目。

# 接下来我们看如何构造稀疏矩阵。定义二维数组st用来存储每一个子数组的计算值，并且其中st[0]对应的是给出列表中所有长度为2**0的子数组对应的计算值，st[1]对应所有长度为2**1的子数组对应的计算值，……以此类推，一直计算到st[x]，其中x是最大的能够满足2**x<len(data)的数字。其中st[i][j]则表示从位置j开始，长度为2**i的子数组的计算值
# 这样，对于st中的每一个数组st[i]，都可以依据上一次计算出来的数组st[i-1]来得出。如果我们要计算以j为起点，长度为2**i的子数组的计算值，可以看作计算以j为起点，长度为2**(i-1)的子数组的值和以j+2**(i-1)为起点，长度为2**(i-1)的子数组的值。因此可以得到递推关系式：st[i][j] = func(st[i-1][j], st[i-1][j+(2**(i-1))])，其中func表示对每一个子数组进行的运算
# 接下来解决最主要的问题，对于一个给出的子数组[l,r]，如何快速计算其对应的计算值？由于我们在计算的时候是按照长度为2的幂来逐步累积的，在计算一个任意子数组的值时，不一定能够凑成一个2的幂，因此我们可以将数组用两个可以重叠的长度为2的幂的子数组来覆盖，因为类似于最大值最小值，最小公倍数这种计算，重叠是没有关系的。综上，首先我们需要找到子数组长度length，并求出一个最大的能够使2**x<=length成立的x值，这样，我们就可以分别从左右端点出发，向另一边延申出长度为2**x的子数组，使两者在子数组中间重叠，然后用这两个更小的子数组对应的值进行计算即可。即：func(st[x][l], st[x][r-2**x+1])

class SparseTable:
    def __init__(self, data, func=max):
        self.func = func
        self.st = [list(data)]
        i, N = 1, len(data)
        m = N.bit_length()

        curMask = 1
        for i in range(1, m+1):
            self.st.append([0]*(N-2*curMask+1))
            for j in range(N-2*curMask+1):
                self.st[i][j] = self.func(self.st[i-1][j], self.st[i-1][j+curMask])
            curMask <<= 1

    def query(self, left, right):
        length = right-left+1
        k = length.bit_length()-1
        return self.func(self.st[k][left], self.st[k][right-(1<<k)+1])

class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        # 在主函数里，我们则需要两个稀疏矩阵，分别用来计算一个任意子数组的最大值和最小值，从而得到这个子数组的"值"
        # 但是我们还需要找到最大的k个子数组的值并累加，同时根据一个原理：从同一个点出发，子数组的长度越长，子数组的值就越大，因此可以先对于每一个位置，计算从它开始一直到数组结尾的子数组的值，加入一个大顶堆中。之后循环k次，每一次取出堆顶元素即可。但是单纯这样可能出现少算的情况，因此对于每一个已经计算的子数组，我们都可以将它的右端点缩减一个位置，然后将其再次压入堆中，一直到弹出的子数组长度都为0为止
        n = len(nums)
        st_Max = SparseTable(nums, max)
        st_Min = SparseTable(nums, min)

        def calc_val(l, r): # 计算一个子数组的值
            return st_Max.query(l, r)-st_Min.query(l, r)

        h = []
        for i in range(n):
            heappush(h, (-calc_val(i, n-1), i, n-1))
        
        res = 0
        while k>0:
            v, l, r = heappop(h)
            v = -v
            res += v
            if r > l:
                heappush(h, (-calc_val(l, r-1), l, r-1)) # 继续计算
            k -= 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,2]
    k = 2
    print(s.maxTotalValue(nums, k))
