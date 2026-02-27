class Solution:
    def binaryGap(self, n: int) -> int:
        last = -1
        i = 0
        res = 0
        while n:
            if n&1:
                if last >= 0:
                    res = max(res, i-last)
                last = i
            n >>= 1
            i += 1
        return res

if __name__ == "__main__":
    s = Solution()
    n = 22
    print(s.binaryGap(n))
