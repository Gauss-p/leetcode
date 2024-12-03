class Solution:
    def checkTwoChessboards(self, c1: str, c2: str) -> bool:
        return (ord(c1[0])+int(c1[1]))%2 == (ord(c2[0])+int(c2[1]))%2

if __name__ == "__main__":
    s = Solution()
    c1 = "a1"
    c2 = "c3"
    print(s.checkTwoChessboards(c1, c2))
