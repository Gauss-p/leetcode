class Solution:
    def minOperations(self, s: str) -> int:
        if s == ''.join(sorted(s)):
            return 0
        if len(s) == 2:
            return -1

        n = len(s)
        mn, mx = min(s), max(s)
        if s[0] == mn or s[-1] == mx:
            return 1
        if s[0] == mx and s[-1] == mn:
            if mx not in s[1:-1] and mn not in s[1:-1]:
                return 3
        return 2

if __name__ == "__main__":
    sl = Solution()
    s = "dog"
    print(sl.minOperations(s))
