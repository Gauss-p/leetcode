class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        k -= 1
        def dfs(n, k):
            if n == 1:
                return 0
            mid = (1<<(n-1)) - 1
            if k > mid:
                return 1-dfs(n-1, 2*mid-k)
            return 1 if k==mid else dfs(n-1, k)
        return str(dfs(n, k))

if __name__ == "__main__":
    s = Solution()
    n, k = 3, 1
    print(s.findKthBit(n, k))
