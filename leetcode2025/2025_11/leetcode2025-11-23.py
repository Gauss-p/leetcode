from typing import List
from sortedcontainers import SortedList

class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        # 分析题目，如果总和模除3为0，那么直接返回总和即可；如果总和模除3为1，那么就需要找到最小的一个模除3为1的数字删除或是找到最小的两个模除3为2的数字删除；如果总和模除3为2，那么就需要找到最小的一个模除3为2的数字删除或是找到最小的两个模除3为1的数字删除
        # 因此，我们需要维护最小的两个模除3为1的数字和最小的两个模除3为2的数字，最后进行判断，而这有两种方法可以实现，一种是直接维护两个数字，但这样判断情况太多，代码较复杂却快；一种是维护两个有序列表，分别存储模除3为1的数字和模除3为2的数字，这样代码简单，判断情况少，但较慢
        tot = sum(nums)
        one = SortedList([float("inf"), float("inf")])
        two = SortedList([float("inf"), float("inf")])
        for i in nums:
            if i%3 == 1:
                one.add(i)
            if i%3 == 2:
                two.add(i)

        if tot%3 == 0:
            return tot
        if tot%3 == 1:
            sub = min(one[0], two[0]+two[1])
            return max(0, tot-sub)

        sub = min(two[0], one[0]+one[1])
        return max(0, tot-sub)

if __name__ == "__main__":
    s = Solution()
    nums = [3,6,5,1,8]
    print(s.maxSumDivThree(nums))
