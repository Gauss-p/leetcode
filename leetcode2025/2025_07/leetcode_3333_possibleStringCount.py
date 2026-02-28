from itertools import accumulate

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        # 最开始，如果字符串的总长度还没有到达k，就意味着无论怎样选都无法选到长度k，答案就是0
        # 之后，我们分两部分考虑，首先，对于原字符串，我们可以将其划分为很多个连续的重复块，比如说aabbccdd就可以被我们拆分成aa,bb,cc,dd，如果不考虑k的问题，那么总共的可能数就是所有重复块的长度的乘积。我们将所有重复块的长度存储到一个列表lengths中，那么我们就不需要考虑
        # 接下来考虑一种特殊情况，如果k没有超过重复块的总数，也就说明无论我们怎样构建初始输入字符串，它的长度都一定大于等于k，这时候直接返回刚才计算出来的res即可
        # 如果不是以上的特殊情况，我们就需要计算长度小于k的初始输入字符串的情况总数，用res减去长度小于等于k的情况，剩下的就是长度大于等于k的情况总数。为了计算长度小于k的情况总数，我们可以用多重背包问题的思路解决。首先定义dp[i][j]表示：在前i组连通块中，能够组成长度为j的初始输入字符串的情况总数。所以i的最大值就是m(m为重复块的总数)，j的最大值就是k-1
        # 假如我们现在要在前i个重复块中构建出一个长度为j的初始输入字符串，那么经过统计，我们知道在第i个重复块中最多能够选lengths[i]个字符，因此，如果在第i个重复块中选择k个字符，我们就需要在前i-1个重复块中选择j-k个字符，以此来达成长度为j的要求，那么最终计算完成后返回dp[m][k-1]即可
        n = len(word)
        if n<k:
            return 0

        modNum = 1_000_000_007
        lengths = [] # 记录所有重复块的长度
        res = 1
        cnt = 0
        for i in range(n):
            cnt += 1
            if i == n-1 or word[i] != word[i+1]:
                lengths.append(cnt)
                res = (res*cnt)%modNum
                cnt = 0

        m = len(lengths)
        if m >= k:
            return res

        k -= m

        dp = [[0]*k for _ in range(m+1)]
        dp[0][0] = 1
        for i in range(m):
            c = lengths[i]-1
            preSum = list(accumulate(dp[i], initial=0)) # 发现在累加时是连续的，可以利用前缀和优化
            for j in range(k):
                dp[i+1][j] = (preSum[j+1]-preSum[max(0, j-c)])%modNum
            # 初始代码如下，在第i个重复块中最多只能选择它的长度个字符
            # for L in range(c+1):
            #     for j in range(k):
            #         if j-L < 0:
            #             continue
            #         dp[i+1][j] += dp[i][j-L]
        return (res-sum(dp[m]) + modNum)%modNum # 防止出现负数

if __name__ == "__main__":
    s = Solution()
    word = "aabbccdd"
    k = 7
    print(s.possibleStringCount(word, k))
