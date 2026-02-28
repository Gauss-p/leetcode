ModNum = 1_000_000_007
MaxN = 10_000
MaxK = 13

# 预处理所有数字的各个质因子个数
Exp = [[] for _ in range(MaxN+1)]
for x in range(2,MaxN+1):
    tmp = x
    i = 2
    while i*i<=tmp:
        cnt = 0
        while tmp%i == 0:
            cnt += 1
            tmp //= i
        if cnt>0:
            Exp[x].append(cnt)
        i += 1
    if tmp>1:
        Exp[x].append(1)

# 预处理所有的组合数
C = [[0]*(MaxK+1) for _ in range(MaxN+MaxK+1)]
for i in range(MaxN+MaxK+1):
    C[i][0] = 1
    for j in range(1, min(i, MaxK)+1):
        C[i][j] = (C[i-1][j]+C[i-1][j-1])%ModNum

class Solution:
    # 通过观察我们可以发现，所谓的理想数组我们可以将其转化成一个“商分数组”，类比差分数组，商分数组中的每一个数都对应当前位置的数字除以原数组中的前面一个数字。即，如果原数组为[a0,a1,a2,...,an]，那么商分数组就是[a0,a1/a0,a2/a1,a3/a2,...,an/a(n-1)]。观察商分数组，因为如果将所有元素相乘可以得到an，所以说，商分数组中的每一个数字都是an的因数。至此，问题转化成了已知一个理想数组的最大值mx，mx的所有质因数的排列有多少种
    # 那么先不考虑mx的质因数怎么求，从最简单的情况入手，如果已经知道mx的一个质因子有k个，并且我们要将这k个插入n个位置，一共有多少种排列方法？可以将其转换成如下问题，已知有k个小球，我们要将其放入n个盒子，有多少种放法？用插挡板的思路，相当于将n+k个小球排列整齐，分成n组，也就是要往其中插入n-1个挡板，在分完组后在每一个组中拿出一个小球，一共拿出n个小球，最后正好剩下k个小球经过了排列。那么这样想，排列方式就有C[n+k-1][n-1]种了，因为一共有n+k-1个空，要插入n-1个挡板，那么转换一下，可以发现插入方式就是C[n+k-1][k]
    # 那么如果已经知道了mx的各个质因数的个数，我们就只需要将每一个都按如上方式计算一遍，最后返回所有的情况数量之和即可
    # 接下来就要求每个数字的各个质因数的个数，从i=2开始枚举，如果x能被i整除就不断地除i，直到x不能被i整除为止，统计除i的次数，即为x中的质因子i的出现次数。用一个数组Exp记录即可
    # 当然我们同样可以用动态规划的方式预处理出所有的组合数，但是前提是我们要确定数组的规模，首先确定k，因为k是mx的质因子个数，所以假设我们用最小的质因子去凑，可以得到最多的质因子个数，因为mx的最大值是10**4，并且2**13<10**4<2**14，所以k的最大值是13。定义出规模，就可以用递推式C[i][j] = C[i-1][j]+C[i-1][j-1]计算即可
    def idealArrays(self, n: int, maxValue: int) -> int:
        totRes = 0
        for i in range(1, maxValue+1):
            res = 1
            for k in Exp[i]:
                # 对于所有的质因子个数都要计算一遍
                res = (res*C[n+k-1][k])%ModNum
            totRes = (totRes+res)%ModNum
        return totRes

if __name__ == "__main__":
    s = Solution()
    n = 2
    maxValue = 5
    print(s.idealArrays(n, maxValue))
