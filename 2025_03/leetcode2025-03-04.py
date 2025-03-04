class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        # 定义cost[i][j]表示将s[i:j+1]转化为回文串的最少操作次数。根据定义可知，cost[i][j]可以由一个更小的问题转换过来，即cost[i+1][j+1]，将s[i:j-1]转化为回文串首先找到将s[i+1:j-1]转化为回文串，然后再考虑s[i]和s[j]是否相等，如果相等，cost[i][j] = cost[i+1][j-1]，否则cost[i][j] = cost[i+1][j-1]+1
        # 这里要注意，因为计算cost[i][j]需要用到cost[i+1][j-1]，所以我们需要保证在计算时先算i+1再算i，先算j-1再算j，这就需要我们倒序遍历i，同时正序遍历j
        cost = [[0]*n for _ in range(n)]
        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                if s[i]==s[j]:
                    cost[i][j] = cost[i+1][j-1]
                else:
                    cost[i][j] = cost[i+1][j-1]+1
        
        k = 3
        # 接下来计算答案。定义dp[i][r]表示将前r个元素分成i个回文串所需的最小操作次数。首先遍历i表示需要将前r个元素分成几段，同时将后面的元素分为(k-i)个。因为一共要分成k段，所以r的右边至少要有k-i个元素，的最大值就是n-(k-i)，又因为左边要分成i段，所以r的左边至少要有i个元素，最小值就是i。同时遍历左端点l，同理，最小值为i，最大值为r。接下来递推关系式就是dp[i][r] = dp[i-1][l]+cost[l][r]，即将前l个元素分为i-1段，将l到r分为一段，即可到达总共i段的要求
        # 因为dp[i]的计算只和dp[i-1]有关，只需循环i，并直接进行计算即可
        dp = cost[0]
        for i in range(1,k):
            for r in range(n-(k-i), i-1, -1):
                tmp = float("inf")
                for l in range(i, r+1):
                    tmp = min(tmp, dp[l-1]+cost[l][r])
                dp[r] = tmp
        return dp[-1]==0

if __name__ == "__main__":
    sl = Solution()
    s = "abcbdd"
    print(sl.checkPartitioning(s))
