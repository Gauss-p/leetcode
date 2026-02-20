from functools import cache

class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        # 考虑动态规划，定义dp[i]表示爱丽丝得到的总分数是i时获胜的概率。根据题目，可以发现当且仅当分数小于k时才能继续抽取纸牌，并且抽取到纸牌的最大分数是maxPts，所以i的最大值也只能是k-1+maxPts。接下来初始化，当i>n时，答案一定是0，并且，当k<=i<=n时，答案一定是1。根据这个，我们就可以初始化出dp[k:k+maxPts]的所有值
        # 然后是状态转移方程，对于一个可以继续抽取纸牌的得分i(也就是i<k)，爱丽丝再抽取一次纸牌能够得到的分数就有maxPts种可能，而如果抽取到的分数是x，那么当前获胜的概率就是dp[i+x]，因此如果要知道dp[i]，我们就需要对所有情况的可能性求和，然后再除以总共的可能数，也就是dp[i] = sum(dp[i+1:i+maxPts+1])/maxPts
        # 注意到上面的递推式中，每一个dp[i]都需要根据之后的元素进行计算，因此我们从后往前循环即可，在循环的同时维护一个数字tot，用来保存dp[i+1:i+maxPts+1]中maxPts个数字的总和，这样，当前的dp[i]就是tot/maxPts，然后在计算完dp[i]之后，还需要更新tot，也就是需要将tot+dp[i]然后将tot-dp[i+maxPts]，这样就将整个窗口向左滑动了一个位置
        # tot = 0
        # dp = [0]*(k+maxPts)
        # for i in range(k, k+maxPts):
        #     if i<=n:
        #         dp[i] = 1
        #         tot += 1 # 首先求出最后maxPts个数字的和

        # for i in range(k-1, -1, -1):
        #     dp[i] = tot/maxPts
        #     tot += dp[i]
        #     tot -= dp[i+maxPts] # 左滑窗口
        # return dp[0]

        # 也可以考虑dfs的算法，定义dfs(score)表示爱丽丝拿到的牌总分数是score时，最终总分不超过n的概率，那么答案就应该是dfs(0)。如果score>=k，就说明当前已经无法继续拿纸牌，因此直接判断，如果score>n，就返回0，否则返回1即可。接下来，就说明当前可以继续拿牌，又因为拿到的牌一共有maxPts种情况，所以我们可以一一列出dfs(score)的表达式，即：
        # dfs(score) = (dfs(score+1)+dfs(score+2)+···+dfs(score+maxPts))/maxPts
        # 并且，当score+1<k时，也就是当score<k-1时，可以得到以下式子：
        # dfs(score+1) = (dfs(score+2)+dfs(score+3)+···+dfs(score+maxPts+1))/maxPts
        # 将上面的两个式子相减，就可以得到：
        # dfs(score)-dfs(score+1) = (dfs(score+1)-dfs(score+maxPts+1))/maxPts
        # 因此，dfs(score) = dfs(score+1)+(dfs(score+1)-dfs(score+maxPts+1))/maxPts (当且仅当score<k-1时成立)
        # 那么我们还差一种情况，也就是score=k-1。当score=k-1时，我们还可以继续拿牌，假设拿到的分数是x，那么只有score+x<=n的时候才能够统计1，否则只能统计0，也就是1<=x<=n-k+1，总共只能统计到n-k+1个1。但是如果maxPts不够x的最大值，我们就只能统计到maxPts个1，因此可以知道：dfs(k-1) = min(n-k+1, maxPts)/maxPts
        @cache
        def dfs(score):
            if score >= k:
                if score>n:
                    return 0
                else:
                    return 1
            if score == k-1:
                return min(n-k+1, maxPts)/maxPts
            return dfs(score+1)+((dfs(score+1)-dfs(score+maxPts+1)))/maxPts
            # ans = 0
            # for i in range(1, maxPts+1):
            #     if score+i>n:
            #         break
            #     ans += dfs(score+i)
            # return ans/maxPts
        return dfs(0)

if __name__ == "__main__":
    s = Solution()
    n = 6
    k = 1
    maxPts = 10
    print(s.new21Game(n, k, maxPts))
