from typing import List
from collections import defaultdict

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        # 移项可得nums[i]-i != nums[j]-j，因此我们用一个字典统计每一个nums[i]-i的值，这样在统计完后直接用总数对数量减去所有“好数对”(不是坏数对)的数量即可得到坏数对的数量。通过统计出来的每一个nums[i]-i的值的个数，我们可以计算出满足(nums[i]-i=nums[j]-j)的所有数对(i,j)的数量
        # 当然我们也可以在一次循环内解决，对于索引i每次先用总数减去cnt[nums[i]-i]，相当于又发现了cnt[nums[i]-i]个好数对，然后再将当前差值nums[i]-i统计一次即可
        cnt = defaultdict(int)
        n = len(nums)
        for i in range(n):
            cnt[nums[i]-i] += 1
        res = n*(n-1)//2
        for kv in cnt.items():
            res -= kv[1]*(kv[1]-1)//2
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [4,1,3,3]
    print(s.countBadPairs(nums))
