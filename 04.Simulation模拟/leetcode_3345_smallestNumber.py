class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            cur = 1
            for i in str(n): cur *= int(i)
            if cur%t == 0:
                return n
            n += 1
        return -1

if __name__ == "__main__":
    s = Solution()
    n, t = 15, 3
    print(s.smallestNumber(n, t))
