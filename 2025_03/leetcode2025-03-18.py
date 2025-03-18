from typing import List

class Solution:
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        def isPrime(x):
            if x==1: return False
            for i in range(2, int(x**(0.5))+1):
                if x%i == 0:
                    return False
            return True
        myMax = lambda x,y : x if x>y else y
        res = 0
        n = len(nums)
        for i in range(n):
            if isPrime(nums[i][i]):
                res = myMax(res, nums[i][i])
            if isPrime(nums[i][n-i-1]):
                res = myMax(res, nums[i][n-i-1])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [[1,2,3],[5,6,7],[9,10,11]]
    print(s.diagonalPrime(nums))
