from collections import defaultdict

class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        n = len(nums)
        preCnt = defaultdict(int)
        sufCnt = defaultdict(int)
        preCnt[0] = sufCnt[0] = 0
        pre, suf = 0, 0
        for i in range(n):
            pre += nums[i]
            suf += nums[n-i-1]
            preCnt[pre] = i+1
            sufCnt[suf] = i+1
        
        res = 10**18
        for k,v in preCnt.items():
            if x-k in sufCnt and sufCnt[x-k]+v <= n:
                res = min(res, sufCnt[x-k]+v)
        return -1 if res==10**18 else res

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,4,2,3]
    x = 5
    print(s.minOperations(nums, x))
