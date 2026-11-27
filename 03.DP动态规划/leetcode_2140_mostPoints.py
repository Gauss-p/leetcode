from typing import List

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        res = [0]*n
        tmp = [0]*(n+1)
        # 定义动态规划数组dp，dp[i]表示从第i个问题开始解决，最高能获得多少分，并且我们可以发现，dp[i]需要从dp[i+questions[i][1]+1]及其之后的元素转换过来，所以我们倒序遍历
        # 用j在i+questions[i][1]+1和n之间循环，dp[i]就是所有dp[j]+questions[i][0]的最大值
        # 所以我们可以用另一个数组tmp，tmp[i]存储dp[i:]的最大值，那么dp[i]=questions[i]+tmp[i+questions[i][1]+1]，同时我们在每一个dp[i]计算完之后更新tmp[i]的值为max(tmp[i+1], dp[i])即可保证tmp[i]存储的是dp[i:]的最大值
        # 因为需要从所有元素开始都计算一遍最高分数，所以最终的答案实际上是dp所有元素的最大值
        # 根据tmp的定义，答案就是tmp[0]
        for i in range(n-1, -1, -1):
            res[i] = questions[i][0]
            if i+questions[i][1]+1<n:
                # 转移方程
                res[i] = max(res[i], questions[i][0]+tmp[i+questions[i][1]+1])
            tmp[i] = max(tmp[i+1], res[i])
        return tmp[0]

if __name__ == "__main__":
    s = Solution()
    questions = [[3,2],[4,3],[4,4],[2,5]]
    print(s.mostPoints(questions))
