from typing import List

class Solution:
    def maxValue(self, nums: List[int], k: int) -> int:
        # 定义两个动态规划列表f和g，其中f[i][j][x]表示:在前i个数字中选择j个数字，是否能够使其或值等于x，而g[i][j][x]表示在第i个数字及以后的数字中，选择j个数字，是否能够使其或值等于x，所以f和g中的所有值都是布尔值true或false
        # 那么对于列表f，如果f[i][j][x]的值为true，也就是说在前i个数字中选择j个数字，能够使其或值等于x，那么f[i+1][j][x]一定为true，就相当于不选第i+1个数字。而如果要选第i+1个数字，就需要在j<k的情况下选择，即f[i+1][j+1][x|nums[i]]为true
        # 同理，对于列表g，因为我们定义的是在第i个数字及以后的数字中选，所以需要倒过来遍历。如果g[i][j][x]的值为true，那么g[i-1][j][x]一定为true，就相当于不选第i-1个数字。而如果要选第i-1个数字，同样需要在j<k的情况下选择，即f[i-1][j+1][x|nums[i-2]]为true。最后这个地方之所以用i-2是因为当前要选的是第i-1个数字，其索引就少1，即为i-2
        # 最后，我们遍历两个长度为k的子序列中间的分界点i，同时分别遍历两个子序列所有可能的或值x和y，逐个进行判断，如果f[i][k][x]为true并且g[i+1][k][y]也为true，那么就说明x^y是一个答案，记录并求最大值即可

        n, m = len(nums), 1<<7
        f = [[[False]*m for _ in range(k+10)] for _ in range(n+10)]
        g = [[[False]*m for _ in range(k+10)] for _ in range(n+10)]

        # 求出f列表
        f[0][0][0] = True
        for i in range(n):
            for j in range(k+1):
                for x in range(m):
                    if f[i][j][x]:
                        # 不选第i+1个数字
                        f[i+1][j][x] = True
                        if j<k:
                            # 选第i+1个数字
                            f[i+1][j+1][x|nums[i]] = True

        # 求g列表
        g[n+1][0][0] = True
        for i in range(n+1, 1, -1):
            for j in range(k+1):
                for x in range(m):
                    if g[i][j][x]:
                        # 不选第i-1个数
                        g[i-1][j][x] = True
                        if j<k:
                            # 选第i-1个数
                            g[i-1][j+1][x|nums[i-2]] = True

        res = 0
        mymax = lambda x,y : x if x>y else y
        for i in range(k, n-k+1):
            for x in range(m):
                for y in range(m):
                    if f[i][k][x] and g[i+1][k][y]:
                        # 存在可能，记录答案
                        res = mymax(res, x^y)

        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,6,7]
    k = 1
    print(s.maxValue(nums, k))
