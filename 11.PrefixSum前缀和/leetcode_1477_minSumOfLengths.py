from typing import List
from collections import defaultdict

class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        # 对于每一个位置，利用前缀和找到以它为左端点且总和为target的子数组长度，同时记录下它左侧所有可能的总和为target的子数组长度最小值，用res每次取这两个值之和的最小值即可得到答案
        n = len(arr)
        cnt = defaultdict(int)
        cnt[0] = 0
        preSum = [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+arr[i]
            cnt[preSum[i+1]] = i+1
        
        before = 10**18
        res = 10**18
        for i in range(n):
            length = 10**18
            if preSum[i]+target in cnt:
                length = cnt[preSum[i]+target]-i
            res = min(res, length+before)
            if preSum[i+1]-target in cnt:
                before = min(before, i-cnt[preSum[i+1]-target]+1)
        return -1 if res==10**18 else res

if __name__ == "__main__":
    s = Solution()
    arr = [3,2,2,4,3]
    target = 3
    print(s.minSumOfLengths(arr, target))
