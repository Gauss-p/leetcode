from typing import List
from math import gcd

class Solution:
    def findGCD(self, nums: List[int]) -> int:
        return gcd(max(nums), min(nums))

if __name__ == "__main__":
    s = Solution()
    nums = [2,10]
    print(s.findGCD(nums))
