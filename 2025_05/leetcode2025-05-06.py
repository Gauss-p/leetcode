from typing import List

class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        res = []
        n = len(nums)
        for i in range(n):
            res.append(nums[nums[i]])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [0,2,1,5,3,4]
    print(s.buildArray(nums))
