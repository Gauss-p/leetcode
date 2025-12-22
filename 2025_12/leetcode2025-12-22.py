from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        # 动态规划，定义dp[j]表示在选择第j列的情况下可以达到的最大保留列数量，因此如果需要选择第j列，那么上一个选择的列必须满足其每一行的值都小于等于第j列对应值，由此可得状态转移方程：dp[j1]=max(dp[j1], dp[j2]+1)，其中第j2列中每一行的值都小于等于第j1列中对应的值
        m, n = len(strs), len(strs[0])
        dp = [1]*n
        for j1 in range(1, n):
            for j2 in range(j1):
                flag = True
                for i in range(m):
                    if strs[i][j2] > strs[i][j1]:
                        flag = False
                        break
                if flag:
                    dp[j1] = max(dp[j1], dp[j2]+1)
        return n-max(dp)

if __name__ == "__main__":
    s = Solution()
    strs = ["babca","bbazb"]
    print(s.minDeletionSize(strs))
