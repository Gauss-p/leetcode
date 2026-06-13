from typing import List

class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        res = ""
        for i in words:
            cur = sum(weights[ord(c)-ord('a')] for c in i)%26
            res += chr(ord('a')+25-cur)
        return res

if __name__ == "__main__":
    s = Solution()
    words = ["abcd","def","xyz"]
    weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]
    print(s.mapWordWeights(words, weights))
