from typing import List
from collections import defaultdict

class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        pos = defaultdict(list)
        for i in range(n):
            pos[nums[i]].append(i)
        
        res = float("inf")
        for p in pos.values():
            for i in range(len(p)-2):
                if p[i+2]-p[i] < res:
                    res = p[i+2]-p[i]
        return res*2 if res != float("inf") else -1

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,1,1,3]
    print(s.minimumDistance(nums))
