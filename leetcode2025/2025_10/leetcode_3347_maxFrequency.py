from typing import List
from collections import defaultdict, Counter

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        # 对于每一个数字，我们都将这个数字加上[-k,k]中的任意一个数后得到的结果统计一次，随后就可以得到每一个值最后可能出现的总次数，然后对于每一个值，求出它可能出现的总次数，假设这个值为k，出现总次数可能是tot，接下来就需要考虑操作次数限制，这时有两种情况，第一种是k在nums中有出现，那么此时nums中原本是k的值就不需要浪费一次操作来变成k，因此需要通过加减操作变成k的数字就一共有tot-nums.count(k)个，再加上numOperations的限制，就可以得出最后能够变成k的数字一共有:nums.count(k)+min(numOperations, tot-nums.count(k))；而如果k在nums中没有出现，则直接用min(numOperations, tot)即可得到最终可以变成k的总数字数量
        diff = defaultdict(int) # 差分数组来统计每个数字出现次数
        cnt = Counter(nums)
        for i in cnt.keys():
            diff[i] += 0
            diff[i-k] += cnt[i]
            diff[i+k+1] -= cnt[i]

        sumDiff = 0
        res = 0
        for k,v in sorted(diff.items()):
            sumDiff += v
            if cnt[k] > 0: # k有出现
                res = max(res, cnt[k]+min(sumDiff-cnt[k], numOperations))
            else: # k没有出现
                res = max(res, min(sumDiff, numOperations))
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,4,5]
    k = 1
    numOperations = 2
    print(s.maxFrequency(nums, k, numOperations))
