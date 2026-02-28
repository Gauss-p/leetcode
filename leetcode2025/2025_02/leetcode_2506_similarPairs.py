from typing import List

class Solution:
    def similarPairs(self, words: List[str]) -> int:
        n = len(words)
        tmpSet = []
        for i in words:
            tmpSet.append(sorted(set(i)))
        res = 0
        for i in range(n):
            for j in range(i+1, n):
                if tmpSet[i] == tmpSet[j]:
                    res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    words = ["aba","aabb","abcd","bac","aabc"]
    print(s.similarPairs(words))
