from typing import List
from collections import defaultdict

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if k >= len(nums):
            return len(set(nums))<len(nums)
        dic = defaultdict(int)
        n = len(nums)
        for i in range(n):
            dic[nums[i]] += 1
            # if dic[nums[i]] >= 2:
            #     return True
            if i<k:
                continue
            if len(dic)<=k:
                return True
            dic[nums[i-k]] -= 1
            if dic[nums[i-k]] == 0:
                dic.pop(nums[i-k])
        return False

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,1]
    k = 3
    print(s.containsNearbyDuplicate(nums, k))
