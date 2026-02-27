# https://leetcode.cn/problems/reverse-bits/?envType=daily-question&envId=2026-02-16
# 190. 颠倒二进制位

class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            res <<= 1
            res |= (n&1)
            n >>= 1
        return res

if __name__ == "__main__":
    s = Solution()
    n = 43261596
    print(s.reverseBits(n))
