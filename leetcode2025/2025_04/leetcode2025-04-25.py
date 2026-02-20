from typing import List
from collections import defaultdict

class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        # 为了方便计算区间[i,j]中满足nums[x]%modulo=k的条件的元素数量，我们可以用前缀和的方法，将nums中所有数字都转换成nums[i]%modulo==k对应的01值，然后求出前缀和，那么preSum[j+1]-preSum[i]就是要求的数量
        # 接下来我们要求出(preSum[j+1]-preSum[i])%modulo=k的数对(i,j)的数量，那么我们可以将原式转换为(preSum[j+1]-preSum[i])%modulo=k%modulo，移项可得(preSum[j+1]-k)%modulo=preSum[i]%modulo，所以对于每一个位置j，我们只需要知道前面有多少个位置i可以满足(preSum[j]-k)%modulo=preSum[i]%modulo即可，用cnt进行统计，就可以在每次循环时用O(1)的时间求出答案，最后统计答案即可
        n = len(nums)
        preSum = [0]*(n+1)
        for i in range(n):
            # 前缀和
            preSum[i+1] = preSum[i]+(nums[i]%modulo==k)
        
        cnt = defaultdict(int)
        res = 0
        for i in range(n+1):
            # 计算(i,j)数对数量
            res += cnt[(preSum[i]-k)%modulo]
            cnt[preSum[i]%modulo] += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,2,4]
    modulo = 2
    k = 1
    print(s.countInterestingSubarrays(nums, modulo, k))
