class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        s += '0'
        return s.count('10') <= 1

if __name__ == "__main__":
    sl = Solution()
    s = "1001"
    print(sl.checkOnesSegment(s))
