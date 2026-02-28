from typing import List
from collections import defaultdict, Counter

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        # 对于每一个数字我们都可以将它加上[-k,k]中的任意一个值，因此为了找到出现次数最大的值，我们可以考虑将所有可能的值对每一个数字加上后统计出现次数，也就是，对于nums中的任意一个数字x，都将[x-k, x+k]统计一次出现次数，这样，我们就可以更好地统计出每一种数字的可能出现频次，然后分别进行第二次计算即可。可以发现，为了将一个区间内的所有数字都加上1，我们可以采用差分数组的方法，对一个线段的两个端点分别操作即可，而这里为了不要浪费过多空间，可以用一个哈希表来存储差分数组中的位置和对应的值，即可减少空间使用量
        # 接下来，对于差分数组中的每一个数我们都将它还原出来，即可得到任意一个数字x出现的次数，假设当前已经求出数字x出现了sumDiff次，也就是说在整个数组中，我们有sumDiff个数字可以通过加减数字得到x，接下来我们就需要考虑numOperations的限制，注意到如果x在原数组中有出现过，那么就不需要浪费次数进行变换，因此需要分情况讨论，当x在原数组中出现过时，就需要将sumDiff减去cnt[x]再和numOperations求最小值，最后加上cnt[x]，否则直接求最小值即可
        diff = defaultdict(int)
        cnt = Counter(nums)
        for x in cnt.keys():
            diff[x] += 0
            diff[x-k] += cnt[x]
            diff[x+k+1] -= cnt[x]
        
        res = 0
        sumDiff = 0
        for i,v in sorted(diff.items()):
            sumDiff += v
            res = max(res, min(sumDiff, numOperations+cnt[i]))
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [5,11,20,20]
    k = 5
    numOperations = 1
    print(s.maxFrequency(nums, k, numOperations))
