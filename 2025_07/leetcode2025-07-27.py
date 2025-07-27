from typing import List

class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        newNums = []
        for i in range(n):
            if len(newNums)==0 or nums[i] != newNums[-1]:
                newNums.append(nums[i])
        m = len(newNums)
        for i in range(1, m-1):
            if (newNums[i-1]<newNums[i] and newNums[i]>newNums[i+1]) or (newNums[i-1]>newNums[i] and newNums[i]<newNums[i+1]):
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,4,1,1,6,5]
    print(s.countHillValley(nums))
