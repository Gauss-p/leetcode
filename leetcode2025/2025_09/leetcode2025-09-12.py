class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return any(i in s for i in "aeiou")

if __name__ == "__main__":
    sl = Solution()
    s = "leetcoder"
    print(sl.doesAliceWin(s))
