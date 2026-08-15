from typing import List

class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n = len(nums)
        tot = 0
        allZero = True
        for i in nums:
            tot ^= i
            allZero &= (i == 0)

        if tot == 0:
            if allZero:
                return 0
            return n-1
        return n

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.longestSubsequence(nums))
