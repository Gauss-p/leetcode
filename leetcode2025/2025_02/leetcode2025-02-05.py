from typing import List
from collections import defaultdict

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        res = []
        tmp = []
        # 定义dfs(i)，返回值为从第i个位置开始选，所有子集的情况，因此答案为dfs(0)
        def dfs(i):
            # 边界条件
            if i == n:
                return [tmp.copy()]

            # 选nums[i]
            ans = []
            x = nums[i]
            tmp.append(x)
            ans += dfs(i+1)
            tmp.pop()

            # 不选nums[i]
            i += 1
            while i<n and nums[i] == x:
                # 跳过重复元素，避免出现重复子集
                i += 1
            ans += dfs(i)
            return ans
        return dfs(0)
        # -------------------------------------------------------
        # res = defaultdict(int)
        # nums.sort()
        # for mode in range(0, 2<<len(nums)):
        #     tmp = []
        #     for i in range(len(nums)):
        #         if (mode>>i)&1:
        #             tmp.append(nums[i])
        #     res[tuple(tmp)] = 1
        # return list(map(list, list(res.keys())))

if __name__ == "__main__":
    s = Solution()
    nums = [4,4,4,1,4]
    print(s.subsetsWithDup(nums))
