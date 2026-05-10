from typing import List
from bisect import *
from sortedcontainers import SortedList

class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        stl = SortedList([(nums[-1], n-1)])
        dp = [-10**18]*n
        dp[n-1] = 0
        for i in range(n-2, -1, -1):
            x = nums[i]
            low, high = x-target, x+target
            l = stl.bisect_left((low, -1))
            r = stl.bisect_left((high+1, -1))-1
            
            for j in range(l, r+1):
                dp[i] = max(dp[i], dp[stl[j][1]]+1)
            stl.add((nums[i], i))
        return dp[0] if dp[0] > 0 else -1
    
if __name__ == "__main__":
    s = Solution()
    nums = [1,3,6,4,1,2]
    target = 2
    print(s.maximumJumps(nums, target))
