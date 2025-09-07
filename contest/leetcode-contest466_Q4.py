class Solution:
    def countBinaryPalindromes(self, n: int) -> int:
        # 用二分查找的方式，对于一个区间[l,r]，我们取它的终点mid，并用构造回文数的方式直接构造二进制回文数，一直到构造出来的回文数能够是小于n的最大的数字时，退出循环。这样，每次退出循环后的l值就可以表示有多少个回文数的左半边能够构造出符合条件的回文数了，也就代表了合法回文数的数量
        # 但是由于构造回文数的时候有两种情况，一个是直接加上自己的反转得到一个长度为偶数的回文数，另一个是在加之前先加上一个中间数字从而构成一个长度为奇数的回文数，但是中间数字又有两种可能，0或1，再算上长度为偶数的情况，就可以将中间数字分成三种情况，一种是空字符串，对应长度为偶数，另外是0和1
        def binarySearch(m):
            l, r = 0, 10**8
            while l<=r:
                mid = (l+r)//2
                b = bin(mid)[2:]
                newNum = int(b+m+b[::-1], 2)
                if newNum <= n:
                    l = mid+1
                else:
                    r = mid-1
            return l

        if n<=1:
            return n+1
        return (binarySearch("")-1)+binarySearch("0")+binarySearch("1")

if __name__ == "__main__":
    s = Solution()
    n = 9
    print(s.countBinaryPalindromes(n))
