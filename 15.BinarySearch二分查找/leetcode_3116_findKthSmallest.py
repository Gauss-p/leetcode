from typing import List
from math import gcd

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        # 如果要通过模拟的方式求出第k小的金额，就算利用数据部分循环的规律进行优化，时间复杂度也会达到O(10^8)，因此，正难则反，由于随着k的增大，其对应的金额一定越来越大，两者的增减趋势相同，故可以考虑通过寻找一个合适的最大金额，将能凑出的比它小的金额数量逼近给出的k，这样，即可直接查到第k小的那个金额。具体思路如下：

        # 假设限定一个最大的金额mx，根据上面的讨论可知，随着这个值的增大，可能的金额总数量也会增大，故如果查找到一个最小的mx，使得能制造出的小于等于mx的金额总数量恰好为k，此时的mx恰好就是能够组合出来的第k小的金额。因此，在二分查找的判断函数check(mx)中，要实现的功能就是：计算“能制造出的小于等于mx的金额”总数量，并判断其与k的大小关系。

        # 如何计算“能制造出的小于等于mx的金额”总数量？假如不考虑倍数之间的重复问题，最直观的想法就是对于coins中的每一种金额x，都累加一个mx//x，这样即可得到：能够由面值为x的硬币组成的，且小于等于mx的金额总数量。但当累加完毕后会发现，coins中两个不同数字的公倍数金额会被计算两次，故对于coins中两个不同数字的公倍数则需要在答案中减去；同样，这样操作完之后，coins中三个不同数字的公倍数就会被减了两次，需要再加回来，以此类推，可以发现，对于n个不同数字的公倍数数量，如果n是奇数，那么就需要在答案中加上，否则就需要减去，这就是容斥原理的应用

        # 综上所述，利用二分查找加容斥原理，即可将这个问题解决
        n = len(coins)
        def check(mid):
            res = 0
            for mask in range(1, 1<<n):
                tot = -1
                cnt = 0
                for i in range(n):
                    if (mask>>i)&1:
                        cnt += 1
                        if tot == -1:
                            tot = coins[i]
                        else:
                            tot = tot*coins[i]//gcd(tot, coins[i])
                if cnt & 1:
                    res += mid//tot
                else:
                    res -= mid//tot
            return res < k
        
        l, r = 0, max(coins)*k
        # 最坏情况就是k个不同面额全部由coins中的最大面额组成，这样“第k小”面额就是k*max(coins)
        while l<=r:
            mid = (l+r)//2
            if check(mid):
                l = mid+1
            else:
                r = mid-1
        return l

if __name__ == "__main__":
    s = Solution()
    coins = [5,2]
    k = 7
    print(s.findKthSmallest(coins, k))
