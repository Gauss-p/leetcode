class Solution:
    def squareIsWhite(self, c: str) -> bool:
        return (ord(c[0])+int(c[1]))%2==1

if __name__ == "__main__":
    s = Solution()
    c = 'a2'
    print(s.squareIsWhite(c))
