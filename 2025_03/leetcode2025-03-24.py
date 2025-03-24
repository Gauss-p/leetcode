from typing import List

class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return sum(1 for i in words if s[:len(i)]==i)

if __name__ == "__main__":
    sl = Solution()
    words = ["a","b","c","ab","bc","abc"]
    s = "abc"
    print(sl.countPrefixes(words, s))
