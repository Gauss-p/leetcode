from typing import List
from collections import defaultdict

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        seats = defaultdict(set)
        for r,s in reservedSeats:
            seats[r].add(s)
        
        res = (n-len(seats))*2
        for i in seats.keys():
            curRow = seats[i]
            flag = True
            for s in range(2, 10):
                if s in curRow:
                    flag = False
                    break
            if flag:
                res += 2
                continue

            for beg in [2,4,6]:
                canSit = True
                for s in range(beg, beg+4):
                    if s in curRow:
                        canSit = False
                        break
                flag |= canSit
                if flag:
                    break
            if flag:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    n = 3
    reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
    print(s.maxNumberOfFamilies(n, reservedSeats))
