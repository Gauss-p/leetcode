class Solution:
    def bitwiseComplement(self, n: int) -> int:
        return (1<<(n.bit_length()+(n==0)))-1-n

if __name__ == "__main__":
    s = Solution()
    n = 5
    print(s.bitwiseComplement(n))
