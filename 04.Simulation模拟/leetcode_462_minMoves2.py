from typing import List

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        tot = sum(nums)
        res = 10**18
        s1 = 0
        for i,v in enumerate(nums):
            res = min(res, i*v-s1+(tot-s1)-(n-i)*v)
            s1 += v
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.minMoves2(nums))
