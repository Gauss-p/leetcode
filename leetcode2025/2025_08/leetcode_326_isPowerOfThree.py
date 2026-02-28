from math import log

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return False if n<=0 else pow(3, round(log(abs(n), 3)))==n

if __name__ == "__main__":
    s = Solution()
    n = 27
    print(s.isPowerOfThree(n))
