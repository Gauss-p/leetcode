from typing import List
from collections import Counter
from bisect import *

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        cnt = Counter(nums)
        mx = max(nums)
        cntGcd = [0]*(mx+1) # cntGcd[i]计算最大公约数是i的数对数量
        for i in range(mx, 0, -1):
            # 在所有是i的倍数的数字中，若有c个数字，则总共可以选择c*(c-1)//2个公因数中有i的数对
            # 但有可能出现最大公因数不只是i，而是i的倍数的可能，因此需要减去所有公因数是i的倍数的数对个数
            # 故需要先计算大数字的cntGcd值，才能在后续的计算中能够找到需要减去多少
            tot = 0
            minus = 0
            for j in range(i, mx+1, i):
                tot += cnt[j]
                minus += cntGcd[j]
            cntGcd[i] = tot*(tot-1)//2-minus

        preSum = [0]*(mx+1)
        for i in range(1, mx+1):
            preSum[i] = preSum[i-1]+cntGcd[i]
        
        return [bisect_left(preSum, i+1) for i in queries]

if __name__ == "__main__":
    s = Solution()
    nums = [2,3,4]
    queries = [0,2,2]
    print(s.gcdValues(nums, queries))
