from typing import List
from math import gcd

class Solution:
    def maxLength(self, nums: List[int]) -> int:
        # 分析子数组最大公因数和最小公倍数的性质可以发现，对于任意一个长度为x的数组，若其中所有元素的最大公因数是gx，最小公倍数是lx，那么实际上相当于gx是数组中所有元素分解质因数后的公共部分，而lx就是除去每个数字的公共部分后之积再乘以gx。也就意味着，整个数组中所有元素之积prod满足：prod = lx*(gx**(x-1))
        # 根据题目，乘积等价子数组就是满足prod = lx*gx的子数组，代入可得gx=gx**(x-1)，那么当x-1=1即x=2时可以发现无论gx是多少都符合要求；而当x>2时，则解得gx=0或gx=1，但由于gx>=1，因此必须满足子数组中的最大公因数是1。
        n = len(nums)
        l = 0
        prod = 1
        res = 2
        for r in range(n):
            # 要加入nums[r]，必须保证窗口所有元素中没有和nums[r]最大公因数不为1的数字，即前面所有元素之积和nums[r]最大公因数必须是1.只要不满足这个条件，就需要将窗口左端点向右滑动。
            while gcd(prod, nums[r]) != 1:
                prod //= nums[l]
                l += 1
            res = max(res, r-l+1)
            prod *= nums[r]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1, 2, 1, 2, 1, 1, 1]
    print(s.maxLength(nums))
