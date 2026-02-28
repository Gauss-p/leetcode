from typing import List

class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        st = set(nums)
        while original in st:
            original *= 2
        return original

if __name__ == "__main__":
    s = Solution()
    nums = [5,3,6,1,12]
    original = 3
    print(s.findFinalValue(nums, original))
