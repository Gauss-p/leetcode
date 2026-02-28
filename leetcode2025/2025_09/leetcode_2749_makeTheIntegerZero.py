class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        # 假如总共执行了k次操作，那么先不考虑2的幂，我们需要先将num1减去k倍num2，然后需要判断得到的数字是否能用k个2的幂的和表示出来。记得到的数字为x，那么如果k>x，无论如何也不可能通过k个2的幂加出一个x，毕竟最小的2的幂也是1.其次，记cnt为x的二进制中1的个数，可以发现，在k<=x的情况下，只要k>=cnt，就一定能找到k个2的幂凑成x。因为我们可以将x中的某个2的幂拆成相同的两个更小的2的幂，这样总数就可以加1了。因此可以满足任意一个大于等于cnt的k
        k = 1
        while True:
            x = num1 - k*num2
            if k>x:
                return -1
            if k>=x.bit_count():
                return k
            k += 1
        return -1

if __name__ == "__main__":
    s = Solution()
    num1, num2 = 3, -2
    print(s.makeTheIntegerZero(num1, num2))
