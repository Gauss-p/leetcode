from typing import List

class Solution:
    def check(self, nums: List[int]) -> bool:
        cnt = 0
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                cnt += 1
        return cnt == 0 or (cnt == 1 and nums[-1] <= nums[0])

if __name__ == "__main__":
    s = Solution()
    nums = [3,4,5,1,2]
    print(s.check(nums))
