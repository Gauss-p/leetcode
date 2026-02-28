from typing import List

class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        res, dis = 0, float("inf")
        for i in nums:
            if abs(i) < dis:
                dis = abs(i)
                res = i
            elif abs(i) == dis:
                res = max(res, i)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [-4,-2,1,4,8]
    print(s.findClosestNumber(nums))
