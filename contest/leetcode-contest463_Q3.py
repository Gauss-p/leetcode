from typing import List

class Solution:
    def minArraySum(self, nums: List[int], k: int) -> int:
        # 考虑动态规划，定义dp[i]表示在nums[i:]中删除可整除和后的最小数组和，那么根据这个定义可以得到，答案就应该是dp[0]。接下来我们需要考虑这个数组的状态转移方程，对于当前循环到的位置i，有两种情况，删除或不删除。如果不删除的话，那么很简单，答案就应该是dp[i+1]，因此对于任意一个dp[i]都可以有dp[i] = dp[i+1]+nums[i]
        # 接下来，如果要删除nums[i]，我们就需要找到一个位置j，使得sum(nums[i:j+1])正好是k的倍数，只有这样，我们才能将连同位置i在内的一部分连续子数组删除，这时候，nums[i]就等于nums[j]了
        # 由于我上面推出了一个sum(nums[i:j+1])，因此这道题目可能还与前缀和数组有关系，想知道[i:j+1]的和，如果预处理出了nums的前缀和数组，就只需要O(1)的时间就可以求出sum(nums[i:j+1])。同时还可以注意到，由于j>i，所以在求dp[i]的时候是需要提前求出i之后的值的，因此这里提示我们需要从后往前遍历
        # 同时我们可以发现，如果两个位置在前缀和数组中对应的数值模除k之后得到的值相等，那么这两个位置之间的子数组就一定可以被k整除，也就是该子数组的和是k的整数倍。因此，在从后往前遍历的时候，如果同时维护一个数组modK，长度为k，其中每一个位置pos表示: 在当前位置i之后已经找到的对应前缀和数组中的值模除k等于pos的位置j，这样，对于一个位置i，就可以快速求出一个大于i的位置j，并且能够使得sum(nums[i:j+1])是k的整数倍
        # 因此可以得到，dp[i] = dp[modK[preSum[i]%k]]，当且仅当dp[modK[preSum[i]%k]]已经有存储的时候
        # 注意，在初始化modK数组的时候，数组的总和模除k对应的位置应当是n，即数组最右侧哨兵，只有这样，才能够正确处理数组总和大于k的情况，或数组总和模除k等于0的情况
        n = len(nums)
        preSum = [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+nums[i] # 前缀和数组
        
        dp = [0]*(n+1)
        modK = [-1]*k
        modK[preSum[-1]%k] = n # 总和对应最后一个位置
        for i in range(n-1, -1, -1):
            dp[i] = dp[i+1]+nums[i] # 不删除第i个数字
            if modK[preSum[i]%k] != -1:
                dp[i] = min(dp[i], dp[modK[preSum[i]%k]]) # 删除第i个数字
            modK[preSum[i]%k] = i # 更新当前对应的modK中的值
        return dp[0]

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,1]
    k = 2
    print(s.minArraySum(nums, k))
