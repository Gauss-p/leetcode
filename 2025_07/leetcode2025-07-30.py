from typing import List
from collections import defaultdict

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # 由于两个数a和b如果进行按位与运算，那么结果a and b一定是小于等于a和b的，因此我们只需要找出数组中最大值连续出现的最大长度，就可以得到答案了
        length = defaultdict(int)
        nums.append(-1)
        n = len(nums)
        last = 0
        maxNum = 0
        for i in range(1, n):
            if nums[i] != nums[i-1]:
                length[nums[i-1]] = max(length[nums[i-1]], i-last)
                last = i
            if nums[i-1] > maxNum:
                maxNum = nums[i-1]
        return length[maxNum]

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,3,2,2]
    print(s.longestSubarray(nums))
