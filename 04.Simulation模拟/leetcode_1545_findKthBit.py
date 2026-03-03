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

        # k -= 1
        # length = (1<<n)-1
        # rev = False
        # for i in range(n-1):
        #     mid = length>>1
        #     if k > mid:
        #         k = mid*2-k
        #         rev = not rev
        #     elif k == mid:
        #         return '0' if rev else '1'
        #     length >>= 1
        # return '1' if rev else '0'

if __name__ == "__main__":
    s = Solution()
    n, k = 3, 1
    print(s.findKthBit(n, k))
