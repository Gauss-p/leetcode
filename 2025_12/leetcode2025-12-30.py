from typing import List
from collections import defaultdict

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def isMagicSquare(i, j):
            tot = defaultdict(int)
            row, col, dia = [0]*3, [0]*3, [0]*2
            for x in range(3):
                for y in range(3):
                    cur = grid[i+x][j+y]
                    tot[cur] += 1
                    if cur >= 10 or cur == 0 or tot[cur] == 2:
                        return False
                    row[x] += cur
                    col[y] += cur
                    if x==y:
                        dia[0] += cur
                    if x+y==2:
                        dia[1] += cur
            return len(set(row))==1 and len(set(col))==1 and len(set(dia))==1

        m, n = len(grid), len(grid[0])
        res = 0
        for i in range(m-2):
            for j in range(n-2):
                if isMagicSquare(i,j):
                    res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
    print(s.numMagicSquaresInside(grid))
