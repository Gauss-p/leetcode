from typing import List

class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if i == sum(map(int, list(str(nums[i])))):
                return i
        return -1

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,2]
    print(s.smallestIndex(nums))
