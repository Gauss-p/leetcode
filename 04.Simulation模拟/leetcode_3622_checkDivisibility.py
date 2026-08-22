class Solution:
    def checkDivisibility(self, n: int) -> bool:
        s, m = 0, 1
        for i in map(int, list(str(n))): s, m = s+i, m*i
        return n%(s+m)==0

if __name__ == "__main__":
    s = Solution()
    n = 23
    print(s.checkDivisibility(n))
