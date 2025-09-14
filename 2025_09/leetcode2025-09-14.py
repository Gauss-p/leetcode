from typing import List
from collections import defaultdict

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def exchange_vowels(w):
            s = ""
            for c in w:
                if c not in "aeiou":
                    s += c
                else:
                    s += "*"
            return s

        wordSet = set(wordlist)
        lowercase = defaultdict(int)
        vowel = defaultdict(int)
        n = len(wordlist)
        for i in range(n-1, -1, -1):
            cur = wordlist[i].lower()
            lowercase[cur] = i
            changed = exchange_vowels(wordlist[i].lower())
            vowel[changed] = i

        for i in range(len(queries)):
            if queries[i] in wordSet:
                continue
            cur = queries[i].lower()
            if cur in lowercase:
                queries[i] = wordlist[lowercase[cur]]
            elif exchange_vowels(cur) in vowel:
                queries[i] = wordlist[vowel[exchange_vowels(cur)]]
            else:
                queries[i] = ""
        return queries

if __name__ == "__main__":
    s = Solution()
    wordlist = ["KiTe","kite","hare","Hare"]
    queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
    print(s.spellchecker(wordlist, queries))
