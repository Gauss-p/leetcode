from collections import defaultdict

class Solution:
    def maxFreqSum(self, s: str) -> int:
        res1, res2 = 0, 0
        cnt = defaultdict(int)
        for c in s:
            cnt[c] += 1
            if c in "aeiou":
                if cnt[c] > res1:
                    res1 = cnt[c]
            else:
                if cnt[c] > res2:
                    res2 = cnt[c]
        return res1+res2

if __name__ == "__main__":
    sl = Solution()
    s = "successes"
    print(sl.maxFreqSum(s))
