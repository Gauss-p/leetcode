class Solution:
    def smallestNumber(self, n: int) -> int:
        return (1<<(len(bin(n))-2))-1

if __name__ == "__main__":
    s = Solution()
    n = 5
    print(s.smallestNumber(n))
