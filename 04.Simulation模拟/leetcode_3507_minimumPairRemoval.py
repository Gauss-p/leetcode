from typing import List

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        def findMinPairs():
            n = len(nums)
            flag = False
            minSum = float("inf")
            ans = [0,0]
            for i in range(1, n):
                if nums[i-1] > nums[i]:
                    flag = True
                if nums[i-1]+nums[i] < minSum:
                    minSum = nums[i-1]+nums[i]
                    ans = [i-1, i]
            return ans if flag else []
        
        res = 0
        while True:
            cur = findMinPairs()
            if cur == []:
                break
            a = nums.pop(cur[1])
            b = nums.pop(cur[0])
            nums.insert(cur[0], a+b)
            res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [5,2,3,1]
    print(s.minimumPairRemoval(nums))
