from typing import List

class Solution:
    def earliestFinishTime(self, landST: List[int], landD: List[int], waterST: List[int], waterD: List[int]) -> int:
        res = 10**18
        l, w = len(landST), len(waterST)
        for i in range(l):
            st1, d1 = landST[i], landD[i]
            for j in range(w):
                st2, d2 = waterST[j], waterD[j]
                res = min(res, st1+d1+max(0, st2-st1-d1)+d2)
                res = min(res, st2+d2+max(0, st1-st2-d2)+d1)
        return res

if __name__ == "__main__":
    s = Solution()
    landST, landD = [2,8], [4,1]
    waterST, waterD = [6], [3]
    print(s.earliestFinishTime(landST, landD, waterST, waterD))
