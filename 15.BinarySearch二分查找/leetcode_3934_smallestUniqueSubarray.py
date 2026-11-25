from typing import List
from collections import defaultdict

class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        # 本题可以使用滑动窗口找出长度为给出值mid的所有子数组，但如果直接用一个列表来模拟计算，无论是计数还是加减元素操作都复杂度很高，因此可以使用“双哈希”的方式，用两个数字代替一个列表(两个数字可以有效防止哈希冲突)
        # 如果要用一个数字代替一个长度为mid的列表lst，则可以使用一个质数b，令一个数字w = lst[0]*pow(b,mid-1)+lst[1]*pow(b,mid-2)+...+lst[mid-1]*pow(b, 0)，即可使用数字w表示列表lst
        # 为防止出现在不同位置计算出相同的w，可以用另一个不同的质数b计算出另一个数字，两个数字共同表示一个位置，即可确定该位置
        b1, m1 = 1_000_07, 1_000_000_007
        # b2, m2 = 1_000_09, 1_000_000_009
        def check(mid):
            pow1 = pow(b1, mid, m1)
            # pow2 = pow(b2, mid, m2)

            w1, w2 = 0, 0
            for i in range(mid):
                w1 = (w1*b1+nums[i])%m1
                # w2 = (w2*b2+nums[i])%m2

            cnt = defaultdict(int)
            cnt[(w1, w2)] = 1
            for i in range(mid, n):
                w1 = (w1*b1+nums[i]-nums[i-mid]*pow1)%m1
                # w2 = (w2*b2+nums[i]-nums[i-mid]*pow2)%m2
                cnt[(w1, w2)] += 1

            for v in cnt.values():
                if v == 1:
                    return True
            return False

        l, r = 1, n
        while l<=r:
            mid = (l+r)//2
            if check(mid):
                r = mid-1
            else:
                l = mid+1
        return l

if __name__ == "__main__":
    s = Solution()
    nums = [3,3,3]
    print(s.smallestUniqueSubarray(nums))
