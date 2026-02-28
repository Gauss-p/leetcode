from typing import List
from collections import deque

class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        # 用动态规划的思路，定义数组dp，其中dp[i]表示前i个数字中极差最大为k的分割方式数。然后考虑状态转移方程，由于我们是从0到i计算dp中的值的，因此我们只需要找出「以第i个数字为右端点的子数组」的左端点取值范围即可，只要找到左端点取值范围，那么dp[i]就等于所有可能的左端点对应的dp中的值之和。不难发现，如果以第i个数即索引为i-1的数字为右端点，子数组范围越大，最大最小值的差值就越大，一直到超过k，因此可以知道合法左端点的取值范围一定是一个连续的区间[left,i-1]，那么为了快速求和，我们就可以采用对dp数组求部分前缀和的方式
        # 接下来我们需要考虑对于每一个索引i，其最小可能左端点left的值是多少，为此我们可以考虑滑动窗口的方式，将上述「合法左端点取值范围」变成一个以i为右端点的窗口，每次对于一个新的右端点，我们都需要检查此时窗口中的极差是否超过k，如果超过，就需要将left向右移动，直至极差小于等于k为止。因此我们还需要有一个数组用来维护窗口中的最大最小值，且需要记录下一些必要的值，从而在右移left时可以快速更新新的极值
        # 因此，可以考虑使用单调栈，分别维护一个单调递增和单调递减的栈，每次更新其中的值，同时需要注意的是，在向这两个栈中添加元素的时候不能直接加nums中对应的值，而需要加入索引，为的是在更新左端点的时候方便检查当前的极值所在位置是否已经被窗口所排斥在外，如果是的话，就需要弹出极值，让次大的极值替换它
        # 同时，在更新左端点的时候，由于我们想要快速计算dp部分前缀和，也就是每次都只保存可能的子数组左端点对应的和，因此在右移最小左端点的时候就需要同时减去部分前缀和中的对应值
        # 综上，我们只需要维护两个单调栈，一个左端点，以及一个dp部分前缀和即可
        n = len(nums)
        modNum = 1_000_000_007
        # 两个单调栈
        minQueue = deque() # 维护最小值
        maxQueue = deque() # 维护最大值
        dp = [0]*(n+1) # 动态规划数组
        dp[0] = 1
        preSum = 0
        left = 0
        for i in range(n):
            preSum += dp[i]
            v = nums[i]
            while minQueue and v<=nums[minQueue[-1]]: # 维护最小值
                minQueue.pop()
            minQueue.append(i)

            while maxQueue and v>=nums[maxQueue[-1]]: # 维护最大值
                maxQueue.pop()
            maxQueue.append(i)

            while nums[maxQueue[0]]-nums[minQueue[0]] > k:
                preSum -= dp[left] # 更新部分前缀和
                left += 1 # 更新最小左端点
                if maxQueue[0] < left:
                    maxQueue.popleft() # 去除窗口外的最大值
                if minQueue[0] < left:
                    minQueue.popleft() # 去除窗口外的最小值
            
            dp[i+1] = preSum
        return dp[n]%modNum
        
if __name__ == "__main__":
    s = Solution()
    nums = [9,4,1,3,7]
    k = 4
    print(s.countPartitions(nums, k))
