from typing import List

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        # 首先从特殊情况开始考虑，假设nums中所有数字二进制都只有一位，即0或1，那么对于nums中至少有一个1的情况，如果我们取出一个1，剩下n-1个数字一共有2^(n-1)种选法，选出来一共有以下两种情况：
        #   1.如果选出了偶数个1，那么我们就把提前拿出来的这个1加进去，得到奇数个1，此时异或和就是1.
        #   2.如果选出了奇数个1，那么我们就不加拿出来的1，此时异或和也为1.
        # 综上，只要有一个1，那么所有选择方案的异或和之和就是2^(n-1)
        # 接下来，对于有多个位的数字，我们将每一个位置拆开考虑，如果在所有数的第m位上出现了一个1，那么对于这个位置的异或和之和就是(2^m)*(2^(n-1))，前者是位权，后者是异或和为1的方案数。那么对于所有位置，只要有1，答案就要加上该位位权乘上2^(n-1)，用乘法分配律，可以发现答案就是2^(n-1)乘所有数相或的值
        # 举个例子，对于[1,3]，n=2，其二进制分别为01和11，对于第0位，两个数字都有1，那么该位的异或和之和就是(2^0)*(2^(2-1))=2，同理，对于第1位，3的第一位是1，那么该位的异或和之和就是(2^1)*(2^(2-1))=4，利用乘法分配律，得到答案就是(2^(2-1))*(2^0+2^1)=(2^(2-1))*(11_(2))，可以发现11即为1|3
        # 因此计算nums中所有数字的或值，在乘以2^(n-1)即可
        res = 0
        n = len(nums)
        for i in nums:
            res |= i
        return res<<(n-1)
        # n = len(nums)
        # def dfs(i, xor):
        #     if i == n:
        #         return xor
        #     return dfs(i+1, xor)+dfs(i+1, xor^nums[i])
        # return dfs(0,0)

if __name__ == "__main__":
    s = Solution()
    nums = [5,1,6]
    print(s.subsetXORSum(nums))
