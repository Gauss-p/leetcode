from typing import List
import numpy as np

class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        # 将nums中奇数变为1，偶数变为-1，然后定义前缀和数组preSum，其中preSum[i]表示nums[:i]中全部变换后的值的总和，那么此时，只要找到一组下标(i,j)能够满足preSum[i]==preSum[j]，就说明nums[i:j]是一个平衡子数组
        # 但是根据题目要求，我们不能将同一个数字重复计算，因此对于一个位置i，我们可以先找到nums[i]的上一个位置last，如果要在preSum[i+1]的位置统计nums[i]，我们必须将preSum中从last+1到i的所有位置都去掉nums[i]对应的值，最后再在preSum[i+1]的位置上加上nums[i]的值，只有这样，我们才能保证当前preSum数组中对于nums[i]的统计只有一次
        # 上面的操作还有一个用处，就是当进行完上面所有的操作后，我们可以保证每一个数字都是在它最后出现的那个位置被统计的，因此如果此时以i为子数组右端点，从位置i向前查找所有可能的平衡子数组时，就可以保证每一个位置对应的preSum中的值全都包含了从它到i之间的所有数字，从而正确计算
        # 最后，在更新完nums[i]后，找到preSum中和preSum[i+1]相等的最左侧位置，即为当前最长平衡子数组的左端点

        last = {}
        n = len(nums)
        # preSum = [0]*(n+1)
        preSum = np.zeros(n+1, dtype=np.int32) # 用numpy构建数组，可以快速对其中一整段位置进行加减法或寻找元素位置
        res = 0
        for i in range(n):
            x = nums[i]
            if x in last:
                preSum[last[x]+1:i+1] -= (1 if x&1 else -1) # 利用numpy快速减法
                # for j in range(last[x]+1, i+1):
                #     preSum[j] -= (1 if x&1 else -1)
            
            preSum[i+1] = preSum[i]+(1 if x&1 else -1) # 更新当前元素

            # indx = -1
            # for j in range(i+1):
            #     if preSum[j] == preSum[i+1]:
            #         indx = j
            #         break
            indx = np.flatnonzero(preSum[:i+1]==preSum[i+1]) # 找到preSum[:i+1]中和preSum[i+1]相等的所有下标
            # if indx != -1:
            #     res = max(res, i-indx+1)
            if indx.size:
                res = max(res, int(i-indx[0]+1)) # 找到最左侧元素
            
            last[x] = i # 更新最后出现位置
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,5,4,3]
    print(s.longestBalanced(nums))
