from typing import List
from collections import defaultdict

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        # 分析题意，可以发现我们需要移除的子数组就是一个总和模除p的余数等于nums的总和模除p的余数的数组，也就是说，如果要移除子数组[i,j)，那么我们需要保证：sum(nums[i:j])%p = sum(nums)%p，如果令sum(nums)%p为target，且用前缀和数组来表示，那么上述条件就变成了：(preSum[j]-preSum[i])%p = target，因此，对于一个子数组右端点j，它的左端点i应当满足以下条件：i<j, 且preSum[i]%p = (preSum[j]%p-target)%p，只有这样才能保证子数组的总和模除p等于target
        # 又因为我们需要求的是子数组长度最小值，所以我们可以在循环的过程中，每次更新对应preSum中的值模除p所存储的位置，用来维护最大左端点，因此之后对于任意一个位置就可以求出符合条件的最大左端点，每次更新答案即可
        n = len(nums)
        preSum = [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+nums[i]
        
        target = sum(nums)%p
        if target == 0:
            return 0

        res = float("inf")
        def init():
            return -float("inf")
        dic = defaultdict(init)
        for i in range(n+1):
            dic[preSum[i]%p] = i
            last = dic[((preSum[i]%p)-target)%p]
            if i-last < res:
                res = i-last
        return -1 if res==len(nums) else res

if __name__ == "__main__":
    s = Solution()
    nums = [3,1,4,2]
    p = 6
    print(s.minSubarray(nums, p))
