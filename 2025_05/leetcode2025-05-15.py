from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(groups)
        last = groups[0]
        res = [words[0]]
        for i in range(1,n):
            if groups[i] != last:
                last = groups[i]
                res.append(words[i])
        return res

if __name__ == "__main__":
    s = Solution()
    words = ["c","a"]
    groups = [0,1]
    print(s.getLongestSubsequence(words, groups))
