from typing import List

class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        nums = set(nums)
        res = []
        for i in range(min(nums), max(nums)+1):
            if i not in nums:
                res.append(i)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,4,2,5]
    print(s.findMissingElements(nums))
