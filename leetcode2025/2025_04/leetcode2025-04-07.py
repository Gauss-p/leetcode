from typing import List
from functools import cache

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # 因为题目要求我们分割成两个元素和相等的子集，也就是说如果nums的总和为tot，那么我们只需要选择部分元素使其总和为tot//2即可，当然前提是tot为偶数
        # 定义dfs(i, s)用来计算nums中前i个数字是否能选择部分元素使其总和为s，那么对于每一个位置我们都有两种方案:选或不选。如果选择nums[i]，那么我们需要做的就是在前i-1个数字中选择部分元素使其和等于s-nums[i]，而如果不选，就需要使其和等于s。按照dfs的定义来翻译，就是dfs(i, s)=dfs(i-1, s-nums[i]) or dfs(i-1, s)
        # 接下来考虑边界条件。如果索引i已经到达-1，说明我们将nums中所有元素都找了一遍，这时候如果s=0，就说明可以选出一个总和为tot//2的子集，返回True，否则返回False。同时，在查找的过程中，我们应保证目标和s始终大于0，所以如果发现s<0就立即返回False
        tot = sum(nums)
        if tot&1:
            # 跳过奇数情况
            return False
        tot //= 2
        n = len(nums)
        @cache
        def dfs(i, s):
            if i < 0:
                # 已经遍历完所有数字
                return s == 0
            if s < 0:
                # 保证目标和s不小于0
                return False
            return dfs(i-1, s-nums[i]) or dfs(i-1, s) #选或不选
        return dfs(n-1, tot)

if __name__ == "__main__":
    s = Solution()
    nums = [1,5,11,5]
    print(s.canPartition(nums))
