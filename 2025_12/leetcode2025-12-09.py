from typing import List
from collections import *

class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        # 对于每一个位置分别计算其对应的数字的两倍在左侧出现次数和右侧出现次数，两者相乘即可得到以当前位置为中间值的三元组个数，累加即可
        modNum = 1_000_000_007
        pre, suf = defaultdict(int), Counter(nums)
        res = 0
        for x in nums:
            suf[x] -= 1
            res += pre[x*2]*suf[x*2]
            pre[x] += 1
        return res%modNum

if __name__ == "__main__":
    s = Solution()
    nums = [6,3,6]
    print(s.specialTriplets(nums))
