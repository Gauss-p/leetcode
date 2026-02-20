from typing import List

class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        pos = [[0]*n for _ in range(m)]
        guards = set(map(tuple, guards))
        walls = set(map(tuple, walls))
        dirs = [(0,1), (0,-1), (1,0), (-1,0)]
        for x,y in guards:
            for dx,dy in dirs:
                nx, ny = x+dx, y+dy
                while nx>=0 and nx<m and ny>=0 and ny<n and ((nx,ny) not in guards) and ((nx,ny) not in walls):
                    pos[nx][ny] = 1
                    nx += dx
                    ny += dy
        res = 0
        for i in range(m):
            for j in range(n):
                res += pos[i][j]
        return n*m-res-len(guards)-len(walls)

if __name__ == "__main__":
    s = Solution()
    m, n = 4, 6
    guards = [[0,0],[1,1],[2,3]]
    walls = [[0,1],[2,2],[1,4]]
    print(s.countUnguarded(m, n, guards, walls))
