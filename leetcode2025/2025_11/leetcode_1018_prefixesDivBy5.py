from typing import List

class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        res = []
        cur = 0
        for i in nums:
            cur = ((cur<<1)+i)%5
            res.append(cur==0)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [0,1,1]
    print(s.prefixesDivBy5(nums))
