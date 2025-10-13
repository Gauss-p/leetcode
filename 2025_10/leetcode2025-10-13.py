from typing import List

class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        n = len(words)
        res = [words[0]]
        last = sorted(words[0])
        for i in range(1, n):
            cur = sorted(words[i])
            if cur != last:
                res.append(words[i])
                last = cur
        return res

if __name__ == "__main__":
    s = Solution()
    words = ["abba","baba","bbaa","cd","cd"]
    print(s.removeAnagrams(words))
