from typing import List
from collections import defaultdict

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        cnt = defaultdict(int)
        for i in nums:
            if cnt[i] == 1:
                return i
            cnt[i] += 1

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,3]
    print(s.repeatedNTimes(nums))
