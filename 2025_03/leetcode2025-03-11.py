from typing import List

class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        myMax = lambda x,y:x if x>y else y
        myMin = lambda x,y:x if x<y else y
        n = len(nums)
        mx = [0]*(n+1)
        mn = [float("inf")]*(n+1)
        for i in range(1,n+1):
            mx[i] = myMax(mx[i-1], nums[i-1])
            mn[n-i] = myMin(mn[n-i+1], nums[n-i])
        
        res = 0
        for i in range(1,n-1):
            if nums[i] > mx[i] and nums[i] < mn[i+1]:
                res += 2
            elif nums[i] > nums[i-1] and nums[i] < nums[i+1]:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.sumOfBeauties(nums))
