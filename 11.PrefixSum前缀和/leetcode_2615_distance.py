from typing import List
from collections import defaultdict

class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0]*n
        def init():
            return [0,0]
        cnt = defaultdict(init)
        for i in range(n):
            x = nums[i]
            res[i] += i*cnt[x][0]-cnt[x][1]

            cnt[x][0] += 1
            cnt[x][1] += i
        
        cnt = defaultdict(init)
        for i in range(n-1, -1, -1):
            x = nums[i]
            res[i] += cnt[x][1]-i*cnt[x][0]
            
            cnt[x][0] += 1
            cnt[x][1] += i
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,1,1,2]
    print(s.distance(nums))
