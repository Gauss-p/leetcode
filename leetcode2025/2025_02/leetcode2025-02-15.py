from typing import List

class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        res = [-1]*n
        for j in range(n):
            y = j
            flag = True
            for i in range(m):
                if grid[i][y]==1 and (y<n-1 and grid[i][y+1]==1):
                    y += 1
                elif grid[i][y]==-1 and (y>0 and grid[i][y-1]==-1):
                    y -= 1
                else:
                    flag = False
                    break
            if flag:
                res[j] = y
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
    print(s.findBall(grid))
