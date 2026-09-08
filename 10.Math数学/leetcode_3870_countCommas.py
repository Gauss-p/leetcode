class Solution:
    def countCommas(self, n: int) -> int:
        return n-999 if n>999 else 0

if __name__ == "__main__":
    s = Solution()
    n = 1002
    print(s.countCommas(n))
