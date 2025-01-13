from typing import List

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        tot = sum(nums)
        pre = 0
        res = 0
        for i in nums[:-1]:
            pre += i
            if 2*pre >= tot:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [10,4,-8,7]
    print(s.waysToSplitArray(nums))
