from typing import List

class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        cnt1, cnt2 = 0, 0
        for i in nums:
            if i<target:
                cnt1 += 1
            elif i == target:
                cnt2 += 1
        return list(range(cnt1, cnt1+cnt2))

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,5,2,3]
    target = 2
    print(s.targetIndices(nums, target))
