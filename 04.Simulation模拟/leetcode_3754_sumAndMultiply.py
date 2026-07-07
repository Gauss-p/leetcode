class Solution:
    def sumAndMultiply(self, n: int) -> int:
        s = str(n)
        new = 0
        tot = 0
        for i in s:
            if '1'<=i and i<='9':
                new = new*10+int(i)
                tot += int(i)
        return new*tot

if __name__ == "__main__":
    s = Solution()
    n = 10203004
    print(s.sumAndMultiply(n))
