from typing import List
from collections import Counter

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        myMax = lambda x,y : x if x>y else y
        cnt = Counter(nums)
        res = 0
        for i in cnt.keys():
            if i+1 in cnt:
                res = myMax(res, cnt[i]+cnt[i+1])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,2,2,5,2,3,7]
    print(s.findLHS(nums))
