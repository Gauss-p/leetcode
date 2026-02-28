from typing import List
from math import sqrt

maxNum = 100001
factors = [0]*maxNum
for i in range(1, maxNum):
    cnt = 0
    tot = 0
    for j in range(1, int(sqrt(i))+1):
        if i%j == 0:
            cnt += 1
            tot += j
            if j*j != i:
                cnt += 1
                tot += i//j
    if cnt == 4:
        factors[i] = tot

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res = 0
        for i in nums:
            res += factors[i]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [21,4,7]
    print(s.sumFourDivisors(nums))
