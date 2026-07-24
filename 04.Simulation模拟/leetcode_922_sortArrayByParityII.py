from typing import List

class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0]*n
        odd, even = 1, 0
        for i in nums:
            if i&1:
                res[odd] = i
                odd += 2
            else:
                res[even] = i
                even += 2
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [4,2,5,7]
    print(s.sortArrayByParityII(nums))
