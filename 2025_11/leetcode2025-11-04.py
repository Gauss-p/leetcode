from typing import List
from collections import Counter

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        def calc(indx):
            cnt = Counter(nums[indx:indx+k])
            item = sorted(list(cnt.items()), key = lambda x:(x[1], x[0]))
            ans = 0
            for i in item[-x:]:
                ans += i[0]*i[1]
            return ans
        
        n = len(nums)
        res = [0]*(n-k+1)
        for i in range(n-k+1):
            res[i] = calc(i)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,2,2,3,4,2,3]
    k, x = 6, 2
    print(s.findXSum(nums, k, x))
