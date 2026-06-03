from typing import List

class Solution:
    def earliestFinishTime(self, landST: List[int], landD: List[int], waterST: List[int], waterD: List[int]) -> int:
        l, w = len(landST), len(waterST)
        minLand, minWater = 10**18, 10**18
        for i in range(l):
            minLand = min(minLand, landST[i]+landD[i])
        for i in range(w):
            minWater = min(minWater, waterST[i]+waterD[i])
        
        res = 10**18
        for i in range(w):
            res = min(res, max(minLand, waterST[i])+waterD[i])
        for i in range(l):
            res = min(res, max(minWater, landST[i])+landD[i])
        return res

if __name__ == "__main__":
    s = Solution()
    landST, landD = [2,8], [4,1]
    waterST, waterD = [6], [3]
    print(s.earliestFinishTime(landST, landD, waterST, waterD))
