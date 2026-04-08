from typing import List

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        diff = [0]*n
        for i in range(1, n):
            diff[i] = nums[i]-nums[i-1]
            if diff[i] == 0:
                return False
        if diff[1] < 0 or diff[-1] < 0:
            return False
            
        simp = [1]
        for i in diff[1:]:
            if simp[-1]*i < 0:
                simp.append(-simp[-1])
        return simp==[1,-1,1]

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,5,4,2,6]
    print(s.isTrionic(nums))
