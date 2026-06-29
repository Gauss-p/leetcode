from typing import List

class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum(i in word for i in patterns)

if __name__ == "__main__":
    s = Solution()
    patterns = ["a","abc","bc","d"]
    word = "abc"
    print(s.numOfStrings(patterns, word))
