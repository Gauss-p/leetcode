from typing import List
from string import *

class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        n = len(code)
        dic = {"electronics":0, "grocery":1, "pharmacy":2, "restaurant":3}
        chars = '0123456789'+ascii_lowercase+ascii_uppercase+'_'
        res = []
        for i in range(n):
            cod, b, ia = code[i], businessLine[i], isActive[i]
            if len(cod)>0 and all(c in chars for c in cod) and b in dic.keys() and ia:
                res.append((dic[b], cod))
        res.sort()
        return [i[1] for i in res]

if __name__ == "__main__":
    s = Solution()
    code = ["SAVE20","","PHARMA5","SAVE@20"]
    businessLine = ["restaurant","grocery","pharmacy","restaurant"]
    isActive = [True,True,True,True]
    print(s.validateCoupons(code, businessLine, isActive))
