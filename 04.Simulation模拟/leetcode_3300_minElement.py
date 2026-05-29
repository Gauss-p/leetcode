from typing import List

class Solution:
    def minElement(self, nums: List[int]) -> int:
        return min(sum(map(int, list(str(i)))) for i in nums)

if __name__ == "__main__":
    s = Solution()
    nums = [10,12,13,14]
    print(s.minElement(nums))
