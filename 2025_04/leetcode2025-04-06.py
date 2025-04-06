from typing import List
from functools import cache

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        # 定义dfs(i)用来计算以i为结尾的最大的整除子集的长度。为了方便，我们从后往前计算，每一次用j从0到i遍历，如果满足nums[i]%nums[j]==0就说明位置i可以由位置j跳转过来，此时根据定义dfs(i)=dfs(j)+1，其中第一项是以j为结尾的最大长度，第二项指的是nums[i]，因为我们已经发现i可以从j跳过来。
        # 但是由于题目要求我们返回一个实实在在的子集而非它的长度，所以我们需要用一个跳转列表from_来记录各个位置的上一个位置，以此类推反推出整个子集。同时，因为我们要求的是最大的长度，所以只有当计算出来的长度是最大值时我们才对当前位置的上一个位置进行记录
        # 最后，循环所有位置，以每一个位置为结尾都计算一次整除子集的长度，并且记录最大的长度对应的结尾位置，这样，通过跳转列表from_就可以从最后一个位置还原出来所有的元素。注意在还原答案后我们不需要再将其顺序反过来，因为题目没有要求我们按顺序返回
        nums.sort()
        n = len(nums)
        from_ = [-1]*n # 跳转列表

        @cache
        def dfs(i):
            res = 0
            for j in range(i):
                if nums[i]%nums[j]:
                    continue
                # 以下都是可以跳转的情况
                tmpLength = dfs(j)
                if tmpLength > res:
                    # 只存储最优跳转方式
                    res = tmpLength
                    from_[i] = j
            return res+1

        maxLength = 0
        end = 0
        for i in range(n):
            tmp = dfs(i)
            if tmp > maxLength:
                # 只存储最大长度对应的结尾
                maxLength = tmp
                end = i

        ans = []
        while end != -1:
            # 还原答案
            ans.append(nums[end])
            end = from_[end]
        return ans

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,4,8]
    print(s.largestDivisibleSubset(nums))
