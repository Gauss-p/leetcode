from typing import List
from collections import defaultdict

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        # 用滑动窗口的思路，自动遍历左端点l，手动滑动右端点r，每次只要找到一个好子数组，就用答案加上n-r+1，因为只要是左端点为l，右端点在r及之后的所有子数组都一定满足好子数组的要求
        # 定义cnt用来记录窗口中各个数字出现的次数，如果加入一个数字x，那么新出现的下标对就有cnt[x]个，此时将总下标对的数量加上cnt[x]即可。手动滑动右端点，只要总下标对的数量大于等于k就退出循环累加答案
        cnt = defaultdict(int)
        n = len(nums)
        res = 0
        ok = 0
        r = 0
        for l in range(n):
            while r<n and ok<k:
                ok += cnt[nums[r]]
                cnt[nums[r]] += 1
                r += 1
            if ok>=k:
                res += (n-r+1)
            cnt[nums[l]] -= 1
            ok -= cnt[nums[l]]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,1,4,3,2,2,4]
    k = 2
    print(s.countGood(nums, k))
