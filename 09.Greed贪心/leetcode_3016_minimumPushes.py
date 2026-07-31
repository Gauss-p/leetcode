from collections import Counter

class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = Counter(word)
        val = sorted(cnt.values(), reverse = True)
        return sum(val[i]*(i//8+1) for i in range(len(val)))

if __name__ == "__main__":
    s = Solution()
    word = "abcde"
    print(s.minimumPushes(word))
