from typing import List
from collections import Counter

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        cnt = Counter(words)
        res = 0
        same = False
        lst = list(cnt.keys())
        for s in lst:
            if cnt[s] == 0:
                continue
            a, b = s[0], s[1]
            if a != b:
                res += 2*min(cnt[s], cnt[b+a])*2
                cnt[b+a] = 0
            else:
                if cnt[s]%2 == 1:
                    same = True
                res += (cnt[s]-cnt[s]%2)*2

        if same:
            res += 2
        return res

if __name__ == "__main__":
    s = Solution()
    words = ["lc","cl","gg"]
    print(s.longestPalindrome(words))
