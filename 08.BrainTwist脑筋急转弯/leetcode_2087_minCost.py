from typing import List

class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        mn = [min(startPos[0], homePos[0]), min(startPos[1], homePos[1])]
        mx = [max(startPos[0], homePos[0]), max(startPos[1], homePos[1])]
        return sum(rowCosts[mn[0]:mx[0]+1])+sum(colCosts[mn[1]:mx[1]+1])-rowCosts[startPos[0]]-colCosts[startPos[1]]

if __name__ == "__main__":
    s = Solution()
    startPos = [1,0]
    homePos = [2,3]
    rowCosts = [5,4,3]
    colCosts = [8,2,6,7]
    print(s.minCost(startPos, homePos, rowCosts, colCosts))
