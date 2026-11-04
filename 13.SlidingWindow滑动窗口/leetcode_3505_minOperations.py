from typing import List
from collections import defaultdict
from heapq import *

# 分析题目，实际上就是要先求出nums中所有长度为x的子数组变成全部元素相等所需要的最少操作次数，然后再通过简单的动态规划计算出再这些子数组中选择恰好k个不重叠的，能够得到的最少总操作次数，即可解决本题。
# 通过462这道题目可以知道，如果想要将一个数组中所有元素通过加1或减1变得相等，则需要先知道这个数组的中位数，然后求所有元素到这个中位数距离之和即可。如何得到一个数组的中位数？这里就需要用到对顶堆的算法了。如果将数组中较小的一半数字存储入一个大顶堆leftHeap中，并将较大的一半数字存储入一个小顶堆rightHeap中，那么只要能够始终保证leftHeap的长度减去rightHeap的长度是0或1，即可保证leftHeap的顶端元素始终是整个数组的中位数。
# 但注意到这两个堆在滑动窗口的更新过程中需要不断删除元素，并加入新的元素，因此可以定义一个懒删除堆的类，用它来模拟两个堆即可通过延迟实际删除操作来快速实现元素的插入和弹出。思路如下：
#   1.维护一个“假装删除”的统计字典lazyRemove，其中lazyRemove[a]=b表示元素a需要被继续删除b次，且还未实际删除，同时维护整个堆的长度和总和，方便在滑动窗口中记录信息；
#   2.在删除函数remove中，如果要删除x，则直接假装删除，将长度减1，总和减x，同时将lazyRemove[x]累加1；
#   3.由于当需要求堆顶元素或删除堆顶元素的时候，如果堆顶元素是在lazyRemove中被统计了的，就需要将它真的删除完，直到剩余堆顶元素在lazyRemove中没有统计到时才能够得到真正的堆顶元素。因此需要一个函数用来执行上述真正删除的操作。
#   4.由于对顶堆的实现可能出现这种情况：在一个堆中插入某个元素后，这个堆中的堆顶元素被挤到另一个堆中。因此还需要一个pushpop函数，用来模拟连续的push和pop操作，返回被挤出来的元素。

class LazyHeap:
    def __init__(self):
        self.heap = []
        self.size = 0
        self.tot = 0
        self.lazyRemove = defaultdict(int)
    
    def remove(self, x):
        # 只记录不删除
        self.lazyRemove[x] += 1
        self.size -= 1
        self.tot -= x
    
    def realRemove(self):
        while self.heap and self.lazyRemove[self.heap[0]] > 0:
            # 只有堆顶元素需要被删除时才删
            self.lazyRemove[self.heap[0]] -= 1
            heappop(self.heap)

    def top(self):
        self.realRemove()
        return self.heap[0]

    def pop(self):
        self.realRemove()
        self.size -= 1
        self.tot -= self.heap[0]
        return heappop(self.heap)
    
    def push(self, x):
        if self.lazyRemove[x] > 0:
            # 这里，如果本来准备要删x却还没删，则新加入的x可以抵消一次删除
            self.lazyRemove[x] -= 1
        else:
            heappush(self.heap, x)
        self.size += 1
        self.tot += x

    def pushpop(self, x):
        self.realRemove()
        if not self.heap or x <= self.heap[0]:
            return x
        self.tot += x-self.heap[0] # 长度不变，总和会变
        return heappushpop(self.heap, x)

class Solution:
    def minCost(self, nums, length):
        n = len(nums)
        ans = [0]*(n-length+1)
        left = LazyHeap() # 大顶堆，用负数
        right = LazyHeap() # 小顶堆，用整数
        for i in range(n):
            v = nums[i]
            if left.size == right.size:
                # 长度为奇数，中位数需要出现在左边，因此需要往左边增加1个元素，但必须考虑它是否对right有影响
                left.push(-right.pushpop(v))
            else:
                # left已经比right多一个元素，必须将一个元素增加到右边。同时考虑新元素对left是否有影响
                right.push(-left.pushpop(-v))
            
            if i<length-1:
                continue
            
            l = i-length+1
            mid = -left.top()
            s1 = mid*left.size+left.tot # 左边需要加1的总数
            s2 = right.tot-mid*right.size # 右边需要减1的总数
            ans[l] = s1+s2

            if nums[l] <= mid:
                # 滑出元素在左边
                left.remove(-nums[l])
                if left.size < right.size: # 维护两者长度差值
                    left.push(-right.pop())
            else:
                # 滑出元素在右边
                right.remove(nums[l])
                if left.size > right.size+1:
                    right.push(-left.pop())
        return ans

    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        costs = self.minCost(nums, x)
        n = len(nums)
        dp = [[0]*(n+1) for _ in range(k+1)]
        # dp[i][j]表示在前j个元素中选i个长度为x的子数组时，最小操作数
        for i in range(1, k+1):
            dp[i][i*x-1] = 10**18
            for j in range(i*x, n-(k-i)*x+1):
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-x]+costs[j-x])
        return dp[k][n]

if __name__ == "__main__":
    s = Solution()
    nums = [5,-2,1,3,7,3,6,4,-1]
    x, k = 3, 2
    print(s.minOperations(nums, x, k))
