class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n-int(str(n)[::-1]))

if __name__ == "__main__":
    s = Solution()
    n = 25
    print(s.mirrorDistance(n))
