from typing import List

class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(start-i) for i in range(len(nums)) if nums[i]==target)

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4,5]
    target = 5
    start = 3
    print(s.getMinDistance(nums, target, start))
