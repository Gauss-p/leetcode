from typing import List

class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m, n = len(boxGrid), len(boxGrid[0])
        for i in range(m):
            cnt = 0
            for j in range(n):
                cur = boxGrid[i][j]
                if cur == "#":
                    cnt += 1
                    boxGrid[i][j] = '.'
                if cur == "*":
                    for k in range(cnt):
                        boxGrid[i][j-k-1] = '#'
                    cnt = 0
                if j == n-1:
                    for k in range(cnt):
                        boxGrid[i][j-k] = '#'
        
        res = [['']*m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                res[j][m-i-1] = boxGrid[i][j]
        return res

if __name__ == "__main__":
    s = Solution()
    boxGrid = [["#",".","#"]]
    print(s.rotateTheBox(boxGrid))
