from typing import List
import heapq

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        numsCopy = nums.copy()
        heapq.heapify(numsCopy)
        for i in range(k):
            tmp = heapq.heappop(numsCopy)
            indx = nums.index(tmp)
            tmp *= multiplier
            nums[indx] = tmp
            heapq.heappush(numsCopy, tmp)
        return nums

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,3,5,6];
    k, multiplier = 5, 2
    print(s.getFinalState(nums, k, multiplier))
