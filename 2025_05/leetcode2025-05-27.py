class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        return (1+n)*n//2 - (m+(n//m)*m)*(n//m)

if __name__ == "__main__":
    s = Solution()
    n = 10
    m = 3
    print(s.differenceOfSums(n, m))
