from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        return target in nums

if __name__ == "__main__":
    s = Solution()
    nums = [2,5,6,0,0,1,2]
    target = 0
    print(s.search(nums, target))
