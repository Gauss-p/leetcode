from typing import List

class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        mx, mn = max(nums), min(nums)
        nums.append(mx)
        n = len(nums)
        last = -1
        res = n-1
        for i in range(len(nums)):
            v = nums[i]
            if v==mx or v==mn:
                res = min(res, n-1-(i-last-1))
                last = i
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,10,7,5,4,1,8,6]
    print(s.minimumDeletions(nums))
