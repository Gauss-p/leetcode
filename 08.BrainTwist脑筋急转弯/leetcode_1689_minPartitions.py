class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(list(n)))

if __name__ == "__main__":
    s = Solution()
    n = "32"
    print(s.minPartitions(n))
