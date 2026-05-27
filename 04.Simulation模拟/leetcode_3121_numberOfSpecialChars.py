class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        n = len(word)
        lPos = [-1]*26
        uPos = [-1]*26
        for i in range(n):
            cur = word[i]
            if 'a' <= cur and cur <= 'z':
                lPos[ord(cur)-ord('a')] = i
            else:
                if uPos[ord(cur)-ord('A')] == -1:
                    uPos[ord(cur)-ord('A')] = i
        return sum(1 for i in range(26) if lPos[i]>=0 and uPos[i]>=0 and lPos[i]<uPos[i])

if __name__ == "__main__":
    s = Solution()
    word = "aaAbcBc"
    print(s.numberOfSpecialChars(word))
