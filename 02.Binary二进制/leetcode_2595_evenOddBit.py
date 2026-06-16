from typing import List

class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        res = [0,0]
        indx = 0
        while n>0:
            if n&1:
                if indx&1:
                    res[1] += 1
                else:
                    res[0] += 1
            n = n>>1
            indx += 1
        return res

if __name__ == "__main__":
    s = Solution()
    n = 50
    print(s.evenOddBit(n))
