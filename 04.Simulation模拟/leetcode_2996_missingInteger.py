from typing import List
from collections import Counter

class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        nums.append(-1)
        mx = nums[0]
        i = 1
        while nums[i-1]+1 == nums[i]:
            mx += nums[i]
            i += 1
        while mx in cnt:
            mx += 1
        return mx

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,2,5]
    print(s.missingInteger(nums))
