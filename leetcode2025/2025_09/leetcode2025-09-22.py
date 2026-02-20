from typing import List
from collections import Counter

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        tot = list(Counter(nums).values())
        mx, cnt = 0, 0
        for v in tot:
            if v > mx:
                mx = v
                cnt = 1
            elif v == mx:
                cnt += 1
        return cnt*mx

        # cnt = sorted(list(Counter(nums).values()), reverse = True)
        # return cnt.count(cnt[0])*cnt[0]

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,2,3,1,4]
    print(s.maxFrequencyElements(nums))
