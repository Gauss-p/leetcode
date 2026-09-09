class Solution:
    def countCommas(self, n: int) -> int:
        res = 0
        cur = 1000
        while cur <= n:
            res += n-cur+1
            cur *= 1000
        return res

if __name__ == "__main__":
    s = Solution()
    n = 1002
    print(s.countCommas(n))
