class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        return ["."*n]+["#"*(n-1)+"."]*(m-1)

if __name__ == "__main__":
    s = Solution()
    m, n = 2, 3
    print(s.createGrid(m, n))
