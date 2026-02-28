from typing import List

class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        nums.append(1)
        zero = 0
        res = 0
        for i in nums:
            if i != 0:
                res += (zero*(zero+1))//2
                zero = 0
            else:
                zero += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,0,0,2,0,0,4]
    print(s.zeroFilledSubarray(nums))
