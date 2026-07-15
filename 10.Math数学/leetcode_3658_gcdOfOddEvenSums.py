from math import gcd

class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        sumOdd = (1+2*n-1)*n//2
        sumEven = (2+2*n)*n//2
        return gcd(sumOdd, sumEven)

if __name__ == "__main__":
    s = Solution()
    n = 4
    print(s.gcdOfOddEvenSums(n))
