class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        # 将11..1每一个位置都分解出来，形成类似：1,10,100...的数字，可以发现，原数字模除k可以变换成分解出来的所有数字模除k之和再模除k，同时可以发现，10%k=((1%k)*10)%k，100%k=((10%k)*10)%k...，总结可得如下递推式：
        # (10**n)%k=((10**(n-1))%k * 10)%k
        # 因此我们可以通过从最低位的1开始，将每个数位对应的模除k的值依次计算出来，并累加，直到累加和是k的倍数为止，此时记录下整个数字中数位的个数，即可得到要求的长度
        # 注意：如果k是2的倍数或是5的倍数，无论如何也不可能用1结尾的数字凑出可以被它整除的数字
        if k%2 == 0 or k%5 == 0:
            return -1
        cur = 1%k
        length = 1
        tot = cur
        while tot != 0:
            cur = (cur*10)%k
            tot = (tot+cur)%k
            length += 1
        return length

if __name__ == "__main__":
    s = Solution()
    k = 3
    print(s.smallestRepunitDivByK(k))
