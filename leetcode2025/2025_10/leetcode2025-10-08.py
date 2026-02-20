from typing import List
from bisect import *

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        n = len(spells)
        res = [0]*n
        for i in range(n):
            target = (success+spells[i]-1)//spells[i]
            indx = bisect_left(potions, target)
            res[i] = len(potions)-indx
        return res

if __name__ == "__main__":
    s = Solution()
    spells = [5,1,3]
    potions = [1,2,3,4,5]
    success = 7
    print(s.successfulPairs(spells, potions, success))
