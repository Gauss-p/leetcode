from typing import List
from heapq import *

class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        n = len(apples)
        i = 0
        q = []
        res = 0
        while i<n or q:
            if i<n and apples[i] > 0:
                # 压入当天成熟的苹果
                heappush(q, (days[i]+i, apples[i]))
            while q and q[0][0] <= i:
                # 每一天就将腐烂的苹果剔除
                heappop(q)
            if q:
                # 每天吃掉一个苹果
                d, a = heappop(q)
                res += 1
                if a>1:
                    # 如果这一批苹果还有剩余，就再次加入
                    heappush(q, (d, a-1))
            i += 1
        return res

if __name__ == "__main__":
    s = Solution()
    apples = [1,2,3,5,2]
    days = [3,2,1,4,2]
    print(s.eatenApples(apples, days))
