class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        n = len(s)
        for i in range(n-1):
            tmp = s[i+1]+s[i]
            if tmp in s:
                return True
        return False

if __name__ == "__main__":
    sl = Solution()
    s = "leetcode"
    print(sl.isSubstringPresent(s))
