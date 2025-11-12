from typing import List
from math import gcd
from functools import reduce 

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # 首先分析一下可能出现的特殊情况：1.如果nums中所有数字的最大公约数都不是1，那么我们无论怎样操作，最后都不可能将nums中所有数字都变成1，因此直接返回-1即可；2.如果nums中有出现1，假设1的个数是ones，那么我们只需要对剩余的所有数字分别进行一次操作：将其和1求最大公约数，即可将所有数字变成1，因此总操作次数就是len(nums)-ones
        # 接下来，剩下的情况就是：nums中的数字可以经过操作变成1，但是nums中原本并没有1。这时候我们就需要找到一个子数组，使得其中所有数字的最大公约数是1，这样，只需要对这个子数组连续操作，最后就可以得到一个1，而根据这个1，我们就可以将原数组中剩余的len(nums)-1个数字通过len(nums)-1次操作全部变为1
        # 而对于一个子数组，如果它的长度是m，且其中所有元素的最大公约数是1，那么我们需要m-1次操作才能将一个数字变成1，因此，只要在nums中找到这样的子数组，总操作次数就是m-1+len(nums)-1
        # 综上，我们只需要找到m的最小值即可
        totGcd = reduce(gcd, nums) # nums中所有数字的最大公约数
        if totGcd != 1:
            return -1
        
        n = len(nums)
        ones = nums.count(1)
        if ones > 0:
            return n-ones
        
        minLength = float("inf")
        for i in range(n):
            curGcd = nums[i]
            for j in range(i+1, n): # 遍历所有可能的子数组
                curGcd = gcd(curGcd, nums[j])
                if curGcd == 1: # 找到符合要求的子数组
                    minLength = min(minLength, j-i+1)
                    break
        return n-1+minLength-1

if __name__ == "__main__":
    s = Solution()
    nums = [2,6,3,4]
    print(s.minOperations(nums))
