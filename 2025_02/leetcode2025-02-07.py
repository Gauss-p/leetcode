from typing import List

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        dirs = [[0,1],[1,0],[0,-1],[-1,0]]
        res = [[0]*n for _ in range(n)]
        def dfs(i, x, y, lastDir):
            if i == n**2+1:
                return
            res[x][y] = i
            nx, ny = x+dirs[lastDir][0], y+dirs[lastDir][1]
            if nx>=0 and nx<n and ny>=0 and ny<n and res[nx][ny]==0:
                dfs(i+1, nx, ny, lastDir)
            else:
                nDir = (lastDir+1)%4
                tmpx, tmpy = x+dirs[nDir][0], y+dirs[nDir][1]
                dfs(i+1, tmpx, tmpy, nDir)
        dfs(1, 0, 0, 0)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 23
    res = s.generateMatrix(n)
    for i in res:
        for j in i:
            print("{: 4}".format(j), end=" ")
        print()
