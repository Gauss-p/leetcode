from typing import List
from collections import defaultdict

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        # 不定长滑动窗口，只要右端点指向的数字还未出现就将其加入，curSum用来维护当前窗口内数字之和，cnt用来维护当前窗口内每一个数字的出现次数，出现次数为0即代表未出现
        n = len(nums)
        r = 0
        curSum = 0
        res = 0
        cnt = defaultdict(int)
        for l in range(n):
            while r<n and cnt[nums[r]] == 0:
                cnt[nums[r]] += 1
                curSum += nums[r]
                r += 1
            res = max(res, curSum)
            cnt[nums[l]] -= 1
            curSum -= nums[l]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [4,2,4,5,6]
    print(s.maximumUniqueSubarray(nums))
