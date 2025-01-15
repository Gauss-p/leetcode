from typing import List
from heapq import *

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        pq = nums
        heapify(pq)
        res = 0
        while len(pq)>=2 and pq[0]<k:
            x = heappop(pq)
            y = heappop(pq)
            heappush(pq, x*2+y)
            res += 1
        return -1 if pq[0]<k else res

if __name__ == "__main__":
    s = Solution()
    nums = [2,11,10,1,3]
    k = 10
    print(s.minOperations(nums, k))
