from typing import List
from collections import Counter

class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        if max(Counter(nums).values()) >= 3:
            return False
        return True

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,2,2,3,4]
    print(s.isPossibleToSplit(nums))
