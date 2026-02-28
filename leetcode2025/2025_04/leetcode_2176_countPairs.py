from typing import List
from collections import defaultdict
from math import gcd

mx = 101
factors = [[] for _ in range(mx)]
for i in range(1, mx):
    for j in range(i, mx, i):
        factors[j].append(i)

class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        # 如果已知一个下标j以及k的值，那么在所有满足nums[i]=nums[j]这个条件的下标i中，我们只需要找到i*j%k=0的i即可。那么为了满足这个条件，我们可以发现，如果已经知道j和k的最大公因数x，那么我们只需令i是k//x的倍数即可，相当于将一个k分成x和k//x，并且j是x的倍数，i是k//x的倍数，那么i*j一定是k的倍数
        # 接下来的问题就是如何在已知一个j的情况下快速求出满足条件的i的个数。为了在确定数值的情况下还要满足一个倍数关系，我们可以在每一次操作完后将(nums[j],f)的所有组成方式统计一次(其中f是j的因数)，这样，在每次计算的时候我们只需要在负责统计的字典中取出(nums[j],k//x)被记录的次数加入答案即可，这样就既保证了nums[i]=nums[j]，同时保证了i*j可以被k整除
        # 为了方便记录每一个值的所有f，我们可以在外面预处理
        n = len(nums)
        cnt = defaultdict(int) # 记录二元组出现的次数
        res = 0
        for j in range(n):
            if j and nums[j]==nums[0]:
                # 预处理时无法处理j=0的所有因数，因此单独处理
                res += 1
            k2 = k//(gcd(k, j))
            res += cnt[(nums[j], k2)] # 记录答案
            for f in factors[j]:
                # 每次将所有情况都统计一次
                cnt[(nums[j], f)] += 1
        return res

        # n = len(nums)
        # res = 0
        # for i in range(n):
        #     for j in range(i+1, n):
        #         if nums[i]==nums[j] and (i*j)%k==0:
        #             res += 1
        # return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,1,2,2,2,1,3]
    k = 2
    print(s.countPairs(nums, k))
