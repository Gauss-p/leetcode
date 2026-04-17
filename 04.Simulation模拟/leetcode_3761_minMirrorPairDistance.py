from typing import List
from collections import defaultdict

class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        n = len(nums)
        res = 10**18
        pos = defaultdict(int)
        for i in range(n):
            if nums[i] in pos:
                res = min(res, i-pos[nums[i]])
            pos[int(str(nums[i])[::-1])] = i
        return -1 if res==10**18 else res

if __name__ == "__main__":
    s = Solution()
    nums = [12,21,45,33,54]
    print(s.minMirrorPairDistance(nums))
