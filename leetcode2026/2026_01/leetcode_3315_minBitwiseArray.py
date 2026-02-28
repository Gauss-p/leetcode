from typing import List

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        res = []
        for i in nums:
            cur = ((i^(i+1))+1)>>2
            if cur == 0:
                res.append(-1)
            else:
                res.append(i-cur)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,3,5,7]
    print(s.minBitwiseArray(nums))
