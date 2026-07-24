from typing import List

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        # 首先对nums进行去重,可以减少循环时间;
        # 之后就要计算所有三元组的异或值,但如果直接用三重循环一定会超时,故可以分两步走:
        #   1.先用双重循环计算出所有二元组可能的异或值,存储到一个set中;
        #   2.再用双重循环将二元组可能的异或值与nums中的其他数值组合,再次异或,即可得到所有可能的三元组异或值.
        # 返回第二次计算出来的不同异或值个数即可.
        st0 = set(nums)
        st1 = set()
        newNums = list(st0)
        n0 = len(st0)
        for i in range(n0):
            for j in range(i+1, n0):
                st1.add(newNums[i]^newNums[j])
        
        st2 = set(nums)
        for i in st1:
            for j in range(n0):
                st2.add(i^newNums[j])
        return len(st2)

if __name__ == "__main__":
    s = Solution()
    nums = [1,3]
    print(s.uniqueXorTriplets(nums))
