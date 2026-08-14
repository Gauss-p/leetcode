from collections import defaultdict

class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        cnt = defaultdict(int)
        r = 0
        res = 0
        for l in range(len(s)):
            while r<len(s) and cnt[s[r]] <= 1:
                cnt[s[r]] += 1
                r += 1
            res = max(res, r-l)
            cnt[s[l]] -= 1
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "bcbbbcab"
    print(sl.maximumLengthSubstring(s))
