from typing import List
from functools import *

class Solution:
    def countStableSubsequences(self, nums: List[int]) -> int:
        # 由于题目要求不能有三个连续的相同奇偶性的数字，因此我们可以考虑用dfs的方式进行构造，构造出所有合法的子序列，记录其个数即可。定义dfs(i, a, b)，表示当前需要处理的是nums中索引为i的数字，并且之前所选的数字的最近两个奇偶性分别为a和b，其中0表示偶数，1表示奇数。那么首先，无论如何我们都可以不选择当前数字，这样的话，由于子序列中最后两个数字没有变化，因此在传入下一层dfs的时候就需要用dfs(i+1, a, b)
        # 而如果我们要选择当前数字，就必须保证当前数字的奇偶性和a,b这三个数字不相同，否则就会出现不合法的情况，因此，当且仅当nums[i]%2==a==b不成立的时候，才能选择当前数字，并且由于最后两个数字变动了，所以继续传入的时候就需要变成dfs(i+1, b, nums[i]%2)
        n = len(nums)
        modNum = 1_000_000_007
        @cache
        def dfs(i, a, b):
            if i == n:
                return 1
            ans = dfs(i+1, a, b)%modNum
            c = nums[i]%2
            if not a == b == c:
                ans = (ans+dfs(i+1, b, c))%modNum
            return ans
        res = (dfs(0, -1, -1)-1+modNum)%modNum
        dfs.cache_clear() # 清空内存，防止溢出
        return res

        # 当然也可以使用动态规划，其中dp[i][j]表示奇偶性为i的数字当前已经连续出现j次的所有子数组数量，那么dp[i][2]只能从dp[i][1]传递而来，且dp[i][1]只能从dp[1-i][1]或dp[1-i][2]传递过来，防止三个重复奇偶性的数字连续
        # modNum = 1_000_000_007
        # dp = [[0]*3 for _ in range(2)]
        # for i in nums:
        #     cur = i%2
        #     dp[cur][2] = (dp[cur][2]+dp[cur][1])%modNum
        #     dp[cur][1] = (dp[cur][1]+dp[cur^1][1]+dp[cur^1][2]+1)%modNum
        # return (dp[0][1]+dp[0][2]+dp[1][1]+dp[1][2])%modNum

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,5]
    print(s.countStableSubsequences(nums))
