class Solution:
    def scoreOfString(self, s: str) -> int:
        res = 0
        n = len(s)
        for i in range(1,n):
            res += abs(ord(s[i])-ord(s[i-1]))
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "hello"
    print(sl.scoreOfString(s))
