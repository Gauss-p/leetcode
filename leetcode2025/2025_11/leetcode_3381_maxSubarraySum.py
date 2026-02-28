from typing import List

class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        # 首先考虑可以计算的子数组需要满足什么条件。如果我们要计算子数组[i,j)，那么需要满足：(j-i)%k=0，也就是说需要满足：j%k=i%k，而在确定右端点j的情况下，为了让这个子数组的和最大，即让preSum[j]-preSum[i]最大，由于preSum[j]是个定值，因此我们就需要找到最小的preSum[i]的值
        # 因此，可以在循环的时候将所有索引按照模除k的值进行归类，对于每一个模除k得到的值，我们都记录一个所有索引对应的preSum中的最小值，这样，直接用当前位置的preSum值减去 之前和当前位置关于k同余的所有位置中对应的preSum中最小值 即可
        n = len(nums)
        preSum = [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+nums[i]
        
        leftSum = [float("inf")]*k # 按照模除k得到的值分类所有索引
        res = -float("inf")
        for i in range(n+1):
            cur = i%k
            if leftSum[cur] != float("inf"): # 之前出现过和i同余的索引
                if preSum[i]-leftSum[cur] > res:
                    res = preSum[i]-leftSum[cur] # 减去最小值，即可得到最大值
            if preSum[i] < leftSum[cur]:
                leftSum[cur] = preSum[i]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2]
    k = 1
    print(s.maxSubarraySum(nums, k))
