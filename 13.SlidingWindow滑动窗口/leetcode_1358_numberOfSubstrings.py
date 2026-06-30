from collections import defaultdict

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        r = 0
        cnt = defaultdict(int)
        res = 0
        for l in range(n):
            while r < n and (cnt['a'] < 1 or cnt['b'] < 1 or cnt['c'] < 1):
                cnt[s[r]] += 1
                r += 1
            if cnt['a'] >= 1 and cnt['b'] >= 1 and cnt['c'] >= 1:
                res += n-r+1
            cnt[s[l]] -= 1
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "abcabc"
    print(sl.numberOfSubstrings(s))
