from typing import List
from bisect import *

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        modNum = 1_000_000_007
        n = len(s)
        pos = []
        preSum = [0]*(n+1)
        nums = [0]
        for i in range(n):
            preSum[i+1] = preSum[i]+int(s[i])
            if s[i] != '0':
                nums.append((nums[-1]*10+int(s[i]))%modNum)
                pos.append(i)

        res = []
        for l,r in queries:
            il = bisect_left(pos, l)
            ir = bisect_right(pos, r)
            cur = (nums[ir]-nums[il]*pow(10, ir-il, modNum))%modNum
            res.append(cur*(preSum[r+1]-preSum[l])%modNum)
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "10203004"
    queries = [[0,7],[1,3],[4,6]]
    print(sl.sumAndMultiply(s, queries))
