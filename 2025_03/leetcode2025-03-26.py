class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        return sum(range(1,min(n+1, k//2+1)))+sum(range(k, k+max(0, n-k//2)))

if __name__ == "__main__":
    s = Solution()
    n, k = 5, 4
    print(s.minimumSum(n, k))
