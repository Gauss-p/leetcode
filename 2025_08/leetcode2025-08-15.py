class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        # 分析4的幂的特征，可以发现，这个数字必须是2的幂，其次，这个数字模除3必须是1。因为对于任意一个4，它模除3都是1，乘起来肯定是1了
        return n>0 and (n&(-n))==n and n%3==1

if __name__ == "__main__":
    s = Solution()
    n = 16
    print(s.isPowerOfFour(n))
