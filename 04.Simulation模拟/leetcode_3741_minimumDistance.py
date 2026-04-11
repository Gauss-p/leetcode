from typing import List
from collections import defaultdict

class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        intMin = -10**10
        res = -intMin
        def init():
            return (intMin, intMin)
        pos = defaultdict(init)
        for i,x in enumerate(nums):
            if i-pos[x][0] < res:
                res = i-pos[x][0]
            pos[x] = (pos[x][1], i)
        return res*2 if res<-intMin else -1

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,1,1,3]
    print(s.minimumDistance(nums))
