from typing import List
from collections import Counter

class Solution:
    def isGood(self, nums: List[int]) -> bool:
        cnt = Counter(nums)
        n = len(nums)-1
        for i in range(1, n):
            if cnt[i] != 1:
                return False
        if cnt[n] != 2:
            return False
        return True

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,3,2]
    print(s.isGood(nums))
