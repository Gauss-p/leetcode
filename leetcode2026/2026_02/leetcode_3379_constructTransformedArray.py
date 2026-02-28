from typing import List

class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0]*n
        for i in range(n):
            res[i] = nums[(i+nums[i])%n]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,-2,1,1]
    print(s.constructTransformedArray(nums))
