from typing import List

class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        mnX, mnY = m, n
        for a,b in ops:
            mnX = min(mnX, a)
            mnY = min(mnY, b)
        return mnX*mnY
    
if __name__ == "__main__":
    s = Solution()
    m,n = 3,3
    ops = [[2,2],[3,3]]
    print(s.maxCount(m,n,ops))
