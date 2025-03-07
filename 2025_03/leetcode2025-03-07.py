from typing import List
from collections import defaultdict,Counter

class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        # 将nums中所有元素进行分组，分组的依据是每个元素模除k的余数。这样经过分组后，任意两个组中的元素之差都不可能是k，因为如果两个数字来源于不同的组，说明两者模除k的余数不同，两者相减就不可能是k，所以美丽子集的个数就是由不同的组中分别选择不同数字的总方案数。注意在计算的过程中需要将每一个组内选择的方案数与答案相乘
        group = defaultdict(Counter)
        for i in nums:
            group[i%k][i] += 1
        ans = 1
        for key in group:
            # 对每组方案数进行计算
            # a[i][0]表示数组，a[i][1]表示这个数组的个数
            a = sorted(group[key].items())
            n = len(a)
            f = [0]*(n+1)
            # f[i]表示前i个数字中选数的方案数，其中f[0]表示0个数，f[m]表示全选，所以需要m+1的长度
            # 而对于f[1]，选择方案一共有第1个数字的个数的总选择数
            f[0] = 1
            f[1] = ((1<<a[0][1])-1)+1
            for i in range(2,n+1):
                # 不选第i个数f[i+1] = f[i]
                f[i] = f[i-1]
                # 选第i个数，分两种情况，第一种是相邻正好差k，这是就需要从前2个位置开始进行跳转，否则从上一个位置跳转，记住每一种情况都需要乘以当前数字的总选择方案数
                if a[i-1][0]-a[i-2][0] == k:
                    f[i] += f[i-2]*((1<<a[i-1][1])-1)
                else:
                    f[i] += f[i-1]*((1<<a[i-1][1])-1)
            # 每次相乘结果
            ans *= f[n]
        return ans-1
        # nums.sort()
        # n = len(nums)
        # res = -1
        # path = []
        # def dfs(lastIndx):
        #     nonlocal res
        #     res += 1
        #     for i in range(lastIndx+1, n):
        #         if nums[i]-k not in path:
        #             path.append(nums[i])
        #             dfs(i)
        #             path.pop()
        # dfs(-1)
        # return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,4,6]
    k = 2
    print(s.beautifulSubsets(nums, k))
