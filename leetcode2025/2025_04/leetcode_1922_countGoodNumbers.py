class Solution:
    def countGoodNumbers(self, n: int) -> int:
        # 偶数有5个，02468，质数有4个，2357，所以答案就是5的偶数位数次方乘以4的奇数位数次方
        return pow(5, (n+1)//2, 1000000007)*pow(4, n-(n+1)//2, 1000000007)%1000000007

if __name__ == "__main__":
    s = Solution()
    n = 50
    print(s.countGoodNumbers(n))
