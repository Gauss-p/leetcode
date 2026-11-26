class Solution:
    def canAliceWin(self, n: int) -> bool:
        cur = 10
        while n >= cur:
            n -= cur
            cur -= 1
        return cur&1==1

if __name__ == "__main__":
    s = Solution()
    n = 12
    print(s.canAliceWin(n))
