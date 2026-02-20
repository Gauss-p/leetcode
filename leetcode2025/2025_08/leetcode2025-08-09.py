class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        # 判断该数是否等于它最后一位1即可
        return False if n==0 else n==(n&(-n))

if __name__ == "__main__":
    s = Solution()
    n = 1
    print(s.isPowerOfTwo(n))
