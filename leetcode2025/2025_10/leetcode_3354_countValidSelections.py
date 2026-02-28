from typing import List

class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        # 对于每一个0的位置，如果它右边的所有数字之和等于左边所有数字之和，那么从它开始，无论往那个方向都可以将所有元素变成0，但如果左右数字之和的差为1，那么只有一个方向可以将所有元素变成0
        res = 0
        preSum, totSum = 0, sum(nums)
        for i in range(len(nums)):
            if nums[i] == 0:
                if preSum == totSum-preSum:
                    res += 2
                if abs(preSum*2-totSum) == 1:
                    res += 1
            preSum += nums[i]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,0,2,0,3]
    print(s.countValidSelections(nums))
