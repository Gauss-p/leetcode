from typing import List
from collections import Counter,defaultdict

modNum = 1_000_000_007
# 计算快速幂
def myPow(a, b):
    res = 1
    while b:
        if b&1:
            res = (res*a)%modNum
        a = (a*a)%modNum
        b >>= 1
    return res%modNum

N = 80
fact = [1]*(N+1)
invFact = [1]*(N+1)
# 这里采用逆元的方式来计算两数相除。逆元的根本就是要将除以一个数转换成乘以一个数，这样更方便我们进行模除
# 而求逆元需要用到费马小定理，表述如下：若a和p互质，那么a**(p-1)%p = 1，将其转化可得a*a**(p-2)%p = 1
# 因此可以发现，在同样模除p的情况下，一个数除以a和乘以a**(p-2)是等价的
# 又因为我们只需要计算组合数，所以只求出各个数字阶乘的逆元即可
def calInv():
    for i in range(1,N+1):
        fact[i] = (fact[i-1]*i)%modNum
        invFact[i] = myPow(fact[i], modNum-2)
calInv()

def myCombination(n, m):
    # 求组合数，利用逆元可以将/((n-m)!*m!)转化为*inv[n-m]*inv[m]，用O(1)的时间求出
    if m<0 or n<m:
        return 0
    return fact[n]*invFact[n-m]*invFact[m]%modNum


class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        # 定义 dp 为一个字典，其key值为元组 (d, even, odd)，d是奇数格子的和减去偶数格子的和
        # even 是剩余未填充的偶数格式数目，初始为 n//2
        # odd 是剩余未填充的奇数格子数目，初始为 n-n//2
        # dp[(d, even, odd)]的值即是情况数，答案为dp[0, 0, 0]
        num = list(map(int, list(num)))
        tot = sum(num)
        if tot&1:
            return 0
        tot //= 2
        evenTot = len(num)//2
        oddTot = len(num)-evenTot
        cnt = Counter(num)

        dp = defaultdict(int)
        #初始情况下，所有格子都不填充，奇偶和的差值当然为0，剩余的空格子数为even和odd
        dp[(0, evenTot, oddTot)] = 1

        # 因为全是数字，下面对每个数字进行计算
        # 为了遍历每个数字，需要将原来数字串中各数字的频数进行统计
        for i in range(10):
            # 准备保存一个新的状态
            newDp = defaultdict(int)

            for odd in range(cnt[i]+1):
                # 遍历奇数位准备放多少个数字i，那么我们可以通过i的总数减去该值来得到偶数位准备放多少个数字i，接下来遍历上一次的所有情况，如果当前情况的偶数位和奇数位剩余个数分别大于等于当前准备放的数量，那么就可以放，并且如果当前情况的排列方式有s种，剩余位置数量分别为e和o，要放入的数量分别为even和odd，那么对于每一种排列都有C(e,even)*C(o,odd)种排列，因此一共有s*C(e,even)*C(o,odd)种新的情况，记录该状态即可
                even = cnt[i] - odd
                curSub = (odd-even)*i
                
                for (t, e, o), s in dp.items():
                    if e<even or o<odd:
                        continue
                    newDelta = s*myCombination(e, even)*myCombination(o, odd)%modNum # 总情况数
                    key = (curSub+t, e-even, o-odd) # 当前状况的键
                    newDp[key] = (newDp[key]+newDelta)%modNum
            dp = newDp # 更新所有状况
        return dp[(0,0,0)]

if __name__ == "__main__":
    s = Solution()
    num = "123"
    print(s.countBalancedPermutations(num))
