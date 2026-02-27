class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        while n&1 != (n>>1)&1:
            n >>= 1
        return n==0

if __name__ == "__main__":
    s = Solution()
    n = 5
    print(s.hasAlternatingBits(n))
