from typing import List
from bisect import *

class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        # 直接暴力模拟，首先将nums排序，然后选择每一种的最小两边组合，用二分查找找到最大的满足条件的最大边即可
        # 另一种方法是从最大的边开始遍历，如果其索引为i，那么i就是从n-1到0遍历的。同时对于每一个最大的边nums[i]，都维护两条较小的边，索引分别l,r，那么如果发现一次nums[l]+nums[r] > nums[i]，又因为nums已经按照从小到大的顺序排序，就可以证明最小的一条边可以选择索引在[l, r-1]中的所有边，因此答案加上r-1-l+1即r-l，同时将中间的边左移一个位置继续判断；否则就将最小的边右移一个位置继续判断，一直到两边重合为止(这个是c++实现的)
        n = len(nums)
        nums.sort()
        res = 0
        for i in range(n-2):
            for j in range(i+1, n-1):
                a, b = nums[i], nums[j]
                indx = bisect_left(nums, a+b)
                if indx > j+1:
                    res += indx-(j+1)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,2,3,4]
    print(s.triangleNumber(nums))
