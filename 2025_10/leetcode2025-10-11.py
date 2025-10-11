from typing import List
from collections import Counter

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        # 根据题目，我们可以发现，如果要选择一个伤害值，那么其实和该伤害值相同的其他所有元素我们都可以选择，因此在计算的时候可以将power中的元素去重，然后用字典统计出不同数字的出现次数，那么在计算的时候直接利用power中的元素值和该值出现的次数相乘即可得到总的伤害值。我们称去重后的power为newPower，且记录出现次数的字典叫做cnt
        # 定义dp[i]表示newPower[:i+1]数组中能够得到的施咒最大总伤害，那么我们需要知道它的递推关系式，如果现在计算的是dp[i]，那么就有两种情况，一种是不选newPower[i]的伤害值，另一种则是选择newPower[i]的伤害值，对于第一种情况，可以直接得出dp[i]=dp[i-1]，而对于第二种情况，我们则需要求出newPower中在第i个元素之前的最后一个能够满足newPower[i]-newPower[j]>2的索引j，如果找到了这个j，就可以直接得出：dp[i]=dp[j]+newPower[i]*cnt[newPower[i]]，而如果没有找到j，那么dp[i]就直接是newPower[i]*cnt[newPower[i]]
        # 综上所述，可以得到以下递推式：当j存在时：dp[i]=max(dp[i-1], newPower[i]*cnt[newPower[i]])；当j不存在时：dp[i] = max(dp[i-1], dp[j]+newPower[i]*cnt[newPower[i]])
        cnt = Counter(power)
        newPower = sorted(list(cnt.keys()))
        n = len(newPower)
        dp = [0]*n
        dp[0] = newPower[0]*cnt[newPower[0]]
        j = -1
        for i in range(1, n):
            dp[i] = dp[i-1] # 不选第i个元素
            while j+1<i and newPower[i]-newPower[j+1]>2:
                j += 1
            if j >= 0:
                # j存在
                dp[i] = max(dp[i], dp[j]+cnt[newPower[i]]*newPower[i])
            else:
                # j不存在
                dp[i] = max(dp[i], cnt[newPower[i]]*newPower[i])
        return dp[n-1]

if __name__ == "__main__":
    s = Solution()
    power = [1,1,3,4]
    print(s.maximumTotalDamage(power))
