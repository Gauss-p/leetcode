from typing import List
from bisect import *

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        cur = list(range(1,10))
        tot = list(range(1,10))
        for _ in range(9):
            nxt = []
            for i in cur:
                if i%10 < 9:
                    nxt.append(i*10+(i%10)+1)
                    tot.append(i*10+(i%10)+1)
            cur = nxt.copy()
        
        il = bisect_left(tot, low)
        ir = bisect_right(tot, high)
        return tot[il:ir]

if __name__ == "__main__":
    s = Solution()
    low, high = 100, 300
    print(s.sequentialDigits(low, high))
