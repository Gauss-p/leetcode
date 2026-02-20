from typing import List

def quick_pow(a, b):
    res = 1
    while b>0:
        if b&1:
            res = (res*a)%MOD_NUM
        a = (a*a)%MOD_NUM
        b >>= 1
    return res

MAX_NUM = 100001
FACT = [0]*MAX_NUM
MOD_NUM = 1_000_000_007
INV_FACT = [1]*MAX_NUM

# 计算组合数的时候，如果用公式C(n,m)=n!/(m!*(n-m)!)，那么在除法的时候就无法同时模除，所以我们可以选择用逆元
# 逆元的计算需要根据费马小定理，即若a与p互质，那么a**(p-1) % p = 1，将其变换可以得到a * a**(p-2) % p = 1
# 又因为 a*(1/a) % p = 1，所以在模除同一个数字的情况下，a**(p-2)和1/a是等价的，这样除以a就可以变成乘以a**(p-2)
# 那么我们就称a**(p-2)就是a的逆元，又因为我们需要计算的是一个数字阶乘的逆元，因此我们可以直接在循环中计算
# 可以采取以下两个方式：1.先计算出所有的数字的阶乘，然后根据每一个数字的阶乘计算它的逆元
#                     2.先计算出最大一个数字的阶乘的逆元，然后循环往前计算
# 第一个方式很容易实现，直接将每一个数字的阶乘套入公式中计算即可
# 但是第二个方式需要说明一下，定义一个数字x的阶乘为fact[x]，x阶乘的逆元为Inv_fact[x]，那么可以知道fact[x]*Inv_fact[x]%modNum = 1，并且对于x的下一个数字x+1，也有fact[x+1]*Inv_fact[x]%modNum = 1，又因为fact[x+1] = fact[x]*(x+1)，所以在模除同一个数字modNum的前提下，就有Inv_fact[x] = Inv_fact[x+1]*(x+1)，因此只要知道后面的数字阶乘的逆元，就可以倒推出前面所有数字的阶乘的逆元

def init():
    FACT[0] = 1
    for i in range(1, MAX_NUM):
        FACT[i] = (FACT[i-1]*i)%MOD_NUM

    INV_FACT[MAX_NUM-1] = quick_pow(FACT[MAX_NUM-1], MOD_NUM-2)
    for i in range(MAX_NUM-1, 0, -1):
        # INV_FACT[i] = quick_pow(FACT[i], MOD_NUM-2)
        INV_FACT[i-1] = INV_FACT[i]*i %MOD_NUM

def comb(n, m):
    return (FACT[n]*INV_FACT[m])%MOD_NUM *INV_FACT[n-m]%MOD_NUM

init()

class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        # 而这道题目的思路如下：首先我们需要在n个数字中选取k个数对，将它们中每一个的两个数字都置为相同的数字，那么就是长度为n的数组中共有n−1对相邻元素，其中需要有k对相邻元素相同，则剩下的n−1−k对相邻元素不同
        # 我们可以把这n−1−k对不同的相邻元素看作隔板，将整个数组分割为n−k段子数组，每段子数组的元素都相同
        # 而第一段子数组中的元素值可以为m中任意一个数字，然后对于第二段开始的后面所有子数组，它们的元素值和前面一段数组的元素值都不能相同，也就是只有m-1个数字可以选，那么因为剩下有n-k-1段，所以每一种分割方式的总答案数就是m*(m-1)**(n-k-1)
        return (comb(n-1, k)*m*quick_pow(m-1, n-k-1))%MOD_NUM

if __name__ == "__main__":
    s = Solution()
    n, m, k = 3, 2, 1
    print(s.countGoodArrays(n, m, k))
