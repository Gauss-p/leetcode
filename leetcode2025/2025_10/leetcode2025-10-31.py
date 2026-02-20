from typing import List
from collections import Counter

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        res = []
        for k,v in cnt.items():
            if v == 2:
                res.append(k)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [0,1,1,0]
    print(s.getSneakyNumbers(nums))
