from math import gcd

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        preGcd = []
        mx = 0
        for i in range(n):
            mx = max(mx, nums[i])
            preGcd.append(gcd(mx, nums[i]))
        preGcd.sort()
        
        return sum(gcd(preGcd[i], preGcd[-1-i]) for i in range(n//2))

if __name__ == "__main__":
    s = Solution()
    nums = [2,6,4]
    print(s.gcdSum(nums))
