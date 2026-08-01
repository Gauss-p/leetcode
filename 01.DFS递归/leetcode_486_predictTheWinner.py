from typing import List
from functools import cache

class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        @cache
        def dfs(l, r, turn):
            if l == r:
                return turn*nums[l]
            resL = nums[l]*turn+dfs(l+1, r, -turn) # 取左边元素
            resR = nums[r]*turn+dfs(l, r-1, -turn) # 取右边元素
            return max(resL*turn, resR*turn)*turn # 还原成真实分数取最大值，模拟两人均将自己分数最大化
        return dfs(0, n-1, 1) >= 0

if __name__ == "__main__":
    s = Solution()
    nums = [1,5,2]
    print(s.predictTheWinner(nums))
