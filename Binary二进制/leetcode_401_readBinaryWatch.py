from typing import List

class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        res = []
        for h in range(12):
            b1 = h.bit_count()
            if b1>turnedOn:
                continue
            for m in range(60):
                b2 = m.bit_count()
                if b1+b2 == turnedOn:
                    cur = str(h)+":"+"{:02}".format(m)
                    res.append(cur)
        return res
    
if __name__ == "__main__":
    s = Solution()
    turnedOn = 1
    print(s.readBinaryWatch(turnedOn))
