from typing import List
from collections import Counter

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        res = cnt[1]-(1-cnt[1]%2)
        for i in cnt.keys():
            if i == 1:
                continue
            beg = i
            cur = 0
            while cnt[beg] >= 2:
                beg *= beg
                cur += 2
            if cnt[beg] >= 1:
                cur += 1
            else:
                cur -= 1
            res = max(res, cur)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [5,4,1,2,2]
    print(s.maximumLength(nums))
