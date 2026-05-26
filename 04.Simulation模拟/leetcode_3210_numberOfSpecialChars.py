from collections import Counter

class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        cnt = Counter(word)
        return sum(1 for i in range(26) if cnt[chr(ord('a')+i)] and cnt[chr(ord('A')+i)])

if __name__ == "__main__":
    s = Solution()
    word = "aaAbcBC"
    print(s.numberOfSpecialChars(word))
