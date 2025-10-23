class Solution:
    def hasSameDigits(self, s: str) -> bool:
        # 推算可以得出，最后剩下的两个数字中，第一个是s的前n-1个数字分别乘以二项式系数并相加，第二个是s的后n-1个数字分别乘以二项式系数并相加，同时，这些二项式系数分别是:C(n-2, 0), C(n-2, 1), ..., C(n-2, n-2)，模拟即可
        cur = 1 # 二项式系数
        sum1, sum2 = 0, 0 # 第一个数字和第二个数字
        n = len(s)-1
        for i in range(n):
            sum1 = (sum1+int(s[i])*cur)%10
            sum2 = (sum2+int(s[i+1])*cur)%10
            if i<n-1:
                cur = cur*(n-(i+1))//(i+1)
        return sum1==sum2

if __name__ == "__main__":
    sl = Solution()
    s = "3902"
    print(sl.hasSameDigits(s))
