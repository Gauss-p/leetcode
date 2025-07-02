from typing import List

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # 动态规划，定义dp[i]表示总和为i的所有元素组合的个数，因此答案就是dp[target]
        # 然后初始化，如果要总和为0，那么一定只有一种组合，即空集，因此dp[0]=1
        # 接下来递推关系式，如果要组成和为i的组合，那么当前一个数字我们可以选择nums中任意一个数字x，并且得到dp[i]=dp[i-x]，因此要将所有情况累加，就需要循环所有可能的x，累加dp[i-x]即可得到dp[i]的答案
        dp = [0]*(target+1)
        dp[0] = 1
        for i in range(1, target+1):
            for x in nums:
                if i-x>=0:
                    dp[i] += dp[i-x]
        return dp[target]

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    target = 4
    print(s.combinationSum4(nums, target))
