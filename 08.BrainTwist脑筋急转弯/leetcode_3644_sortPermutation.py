from typing import List

class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        res = -1
        for i,v in enumerate(nums):
            if i!=v:
                res &= (i&v)
        return 0 if res==-1 else res

if __name__ == "__main__":
    s = Solution()
    nums = [0,3,2,1]
    print(s.sortPermutation(nums))
