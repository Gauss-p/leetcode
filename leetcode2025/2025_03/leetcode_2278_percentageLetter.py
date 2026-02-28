class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        return int(s.count(letter)*100/len(s))

if __name__ == "__main__":
    sl = Solution()
    s = "foobar"
    letter = "o"
    print(sl.percentageLetter(s, letter))
