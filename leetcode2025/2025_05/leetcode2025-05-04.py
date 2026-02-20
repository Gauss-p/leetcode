from typing import List
from collections import defaultdict

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        cnt = defaultdict(int)
        res = 0
        for x,y in dominoes:
            if x>y:
                x,y = y,x
            res += cnt[(x,y)]
            cnt[(x,y)] += 1
        return res

if __name__ == "__main__":
    s = Solution()
    dominoes = [[1,2],[2,1],[3,4],[5,6]]
    print(s.numEquivDominoPairs(dominoes))
