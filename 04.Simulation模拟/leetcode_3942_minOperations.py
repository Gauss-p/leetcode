from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        if len(nums) == 2:
            return int(nums[0] > nums[1])

        n = len(nums)
        cnt1, cnt2 = 0, 0
        pos1, pos2 = 0, 0
        for i in range(n):
            if nums[i-1] < nums[i]:
                cnt1 += 1
                pos1 = i
            if nums[i-1] > nums[i]:
                cnt2 += 1
                pos2 = i
                
        if min(cnt1, cnt2) > 1:
            return -1
        
        res = 0 if cnt1 >= cnt2 else 1
        if min(cnt1, cnt2) == 0:
            return res
            
        pos = pos1 if cnt1 == 1 else pos2
        return res+ (min(pos, n-pos) if res else min(pos, n-pos+2))

if __name__ == "__main__":
    s = Solution()
    nums = [0,2,1]
    print(s.minOperations(nums))
