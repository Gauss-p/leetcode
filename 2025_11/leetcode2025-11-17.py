from typing import List

class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        last = -1
        for i in range(n):
            if nums[i] == 1:
                if last == -1:
                    last = i
                    continue
                if i-last-1 < k:
                    return False
                last = i
        return True

if __name__ == "__main__":
    s = Solution()
    nums = [1,0,0,0,1,0,0,1]
    k = 2
    print(s.kLengthApart(nums, k))
