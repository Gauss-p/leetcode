from collections import Counter

class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        return Counter(s1[::2])==Counter(s2[::2]) and Counter(s1[1::2])==Counter(s2[1::2])

if __name__ == "__main__":
    s = Solution()
    s1, s2 = "abcdba", "cabdab"
    print(s.checkStrings(s1, s2))
