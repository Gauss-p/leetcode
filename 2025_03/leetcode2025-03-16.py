from string import ascii_lowercase

class Solution:
    def largestVariance(self, s: str) -> int:
        myMax = lambda x,y: x if x>y else y
        n = len(s)
        res = 0
        # 因为题目要求的是字符的最大出现次数与最小出现次数之差，就是在一个子字符串中的两种字符出现次数之差，所以我们可以遍历两个字符，并在字符串s中统计其中一个的最大出现次数与另一个最小出现次数之差即可
        # 利用python的string库中的ascii_lowercase，双重循环遍历所有的两个小写字符的情况。注意，因为我们要求的是两个不同字母出现次数之差，所以在循环过程中要跳过两个字母相同的情况
        for a in ascii_lowercase:
            for b in ascii_lowercase:
                if a==b: continue
                # 对于当前循环到的两个不同字符ab，我们需要找的是(a在字符串中出现的最大次数减去b在字符串中出现的最小次数)的最大值，为了记录方便，在之后我们称前面的那个最大值为最大波动值
                # 定义动态规划数组dp[i+1][j]表示在字符串中，以s[i]为结尾的子字符串的最大波动值。而j只有0和1两个取值，0表示子数组中可以没有字符b，1表示子数组中一定有字符b。当然我们可以保证一定有字符a。而为了计算波动值方便，我们定义字符a对应的值为1，字符b对应-1，其他对应0。这样，问题就转化为求一个数组的最大子数组和
                # 对于状态转移方程，首先，无论如何，dp[i+1][0]都是max(dp[i][0], 0)+v(其中v即为1,-1或0)，而对于dp[i+1][1]，我们分三种情况讨论，如果s[i]=a，那么dp[i+1][1]就必须由dp[i][1]转移，并且波动值加1，如果s[i]=b，那么dp[i+1][1]就变成了dp[i+1][0]，因为以s[i]结尾就一定包含了b，而如果s[i]既不是a也不是b，那么dp[i+1][1]就保持原样，即dp[i][1]
                dp0, dp1 = 0, -float("inf")
                # 为了压缩空间，我们发现计算dp[i+1]时只与dp[i]有关，所以我们用dp0代表dp[i+1][0]，用dp1代表dp[i+1][1]，这样直接替代源代码即可
                # dp = [[0, 0] for _ in range(n+1)]
                # dp[0] = [0, -float("inf")]
                for i in range(n):
                    c = s[i]
                    if c==a:
                        # 第一种情况
                        dp0 = myMax(dp0, 0)+1
                        dp1 = dp1+1
                        # dp[i+1][0] = myMax(dp[i][0], 0)+1
                        # dp[i+1][1] = dp[i][1]+1
                    elif c==b:
                        # 第二种情况
                        dp0 = myMax(dp0, 0)-1
                        dp1 = dp0
                        # dp[i+1][0] = myMax(dp[i][0], 0)-1
                        # dp[i+1][1] = dp[i+1][0]
                    else:
                        # 第三种情况
                        dp0 = myMax(dp0, 0)
                        dp1 = dp1
                        # dp[i+1][0] = myMax(dp[i][0], 0)
                        # dp[i+1][1] = dp[i][1]
                    res = myMax(res, dp1)
                    # res = myMax(res, dp[i+1][1])
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "aababbb"
    print(sl.largestVariance(s))
