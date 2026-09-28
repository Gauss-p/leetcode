from typing import List
from collections import Counter

class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        res = []
        cnt = Counter(nums)
        n = max(cnt.values())
        for i in range(n):
            tmp = []
            for j in cnt:
                if cnt[j] > 0:
                    tmp.append(j)
                    cnt[j] -= 1
            res.append(tmp)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,4,1,2,3,1]
    print(s.findMatrix(nums))
