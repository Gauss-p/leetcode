class Solution:
    def checkString(self, s: str) -> bool:
        n = len(s)
        a, b = -1, -1
        for i in range(n):
            if b == -1 and s[i] == 'b':
                b = i
            if s[i] == 'a':
                a = i
        return a<b if a!=-1 and b!=-1 else True

if __name__ == "__main__":
    sl = Solution()
    s = "aaabbb"
    print(sl.checkString(s))
