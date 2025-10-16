from typing import List
from collections import defaultdict

class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        # 首先分析操作后数组和原数组nums之间的共同特征，可以发现，由于操作后数组是在原数组的每一个数字上加或减去多个value，因此如果我们将nums和操作后数组的每一个数字都模除value，最后就会发现两个数组完全相等，因此，为了判断nums在操作后缺失的最小非负整数，就可以用一个数字从0开始模拟操作后数组，每一次判断nums中所有元素模除value后有没有和当前数字模除value后的值相等的，如果有，就将nums中对应值删除，否则就将当前数字返回，这就是缺失的数字
        # 注意，将nums中对应值删除可以用字典来做，用每个数字模除value后得到的值作为键，这样的值的个数作为值，那么每次就直接判断当前数字模除value在字典中对应的值是否大于0即可，只要大于0，就可以匹配到一个数字，将其值减1，否则就返回当前值即可
        cnt = defaultdict(int)
        for i in nums:
            cnt[i%value] += 1
        i = 0 # 模拟从0开始的非负整数
        while True:
            if cnt[i%value] == 0:
                # 没有数字可以匹配
                return i
            cnt[i%value] -= 1
            i += 1

if __name__ == "__main__":
    s = Solution()
    nums = [1,-10,7,13,6,8]
    value = 5
    print(s.findSmallestInteger(nums, value))
