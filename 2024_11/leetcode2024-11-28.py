class Solution:
    def countOfPairs(self, nums) -> int:
        # 用动态规划的方法，定义dp[i][j]表示当arr1[i]=j时，前i+1位上填的数组对方案总数，所以，对于dp[i][v2]，我们只需考虑前一位上填的数字的所有可能即可，我们假设前一位即arr[i-1]填的是v1，那么v1需要满足以下条件：1.v1<=v2 2.nums[i-1]-v1>=nums[i]-v2。
        # 其中第一个条件是为了保证arr1的非递减性，第二个条件则是为了保证arr2的非递增性，同时我们还要保证arr1和arr2中所有数均为非负数，即需要保证nums[i]-v2>=0(因为nums[i-1]-v1已经比nums[i]-v2大了，所以我们就不用考虑nums[i-1]的问题)，最后，dp[i][v2]就是所有满足条件的v1对应的dp[i-1][v1]数值之和
        # 在所有都计算完以后，答案就是dp[n-1]内所有数值之和
        n = len(nums)
        modNum = 1000000007
        dp = [[0]*51 for _ in range(n)]
        # 题目保证nums中最大值为50，所以dp[i]的规模设置为51即可
        for j in range(nums[0]+1):
            # 对于dp[0]，因为它只代表一位，不存在增减性的问题，所以只要填nums[0]以内的数都可以
            dp[0][j] = 1
        for i in range(1, n):
            for v2 in range(nums[i]+1):
                for v1 in range(v2+1):
                    if nums[i-1]-v1 >= nums[i]-v2 and nums[i]-v2 >= 0:
                        # v1<=v2的条件已经在循环条件里面了
                        dp[i][v2] = (dp[i][v2]+dp[i-1][v1])%modNum
        # 统计答案
        res = 0
        for i in dp[n-1]:
            res = (res+i)%modNum
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,3,2]
    print(s.countOfPairs(nums))