class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        return 0 if abs(x-z)==abs(y-z) else (1 if abs(x-z)<abs(y-z) else 2)

if __name__ == "__main__":
    s = Solution()
    x, y, z = 2, 7, 4
    print(s.findClosest(x, y, z))
