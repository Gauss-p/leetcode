class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return ((n+1)//2 * (m//2)) + ((n//2) * ((m+1)//2))

if __name__ == "__main__":
    s = Solution()
    n, m = 3, 2
    print(s.flowerGame(n, m))
