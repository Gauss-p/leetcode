from typing import List

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        # 除去n<=2的情况不计，剩下的情况中答案均为(1<<n.bit_length())，这不仅可以用暴力计算前几个n的答案来找到规律，还可以用数学方法进行证明：
        # 假设n=5，即为二进制的101，那么如果取两个二进制数，100，011即可凑出111，这就是能够凑出来的最大的数了，但由于要取三个数，因此将011分成两半，分别为010和001，即可用三个数凑出同样的最大值，利用同样的方法，可以凑出所有小于111的值
        # 对于n>=3(令mx=1<<n.bit_length())，总可以找到1,2,3三个数字使异或值变为0，因此从0到mx-1，总共正好有mx个数字
        n = len(nums)
        if n <= 2:
            return n
        return 1<<n.bit_length()

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.uniqueXorTriplets(nums))
