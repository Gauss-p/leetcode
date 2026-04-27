from typing import List

class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        # 一个编号对应可以朝两个方向走，如果相邻两个街道中存在两个相反方向，那么它们一定可以联通
        pairs = ((),
            ((0,1),(0,-1)),
            ((1,0),(-1,0)),
            ((0,-1),(1,0)),
            ((1,0),(0,1)),
            ((0,-1),(-1,0)),
            ((0,1),(-1,0)))
        tot = m*n
        g = [[] for _ in range(tot)]
        for i in range(tot):
            x, y = i//n, i%n
            cur = grid[x][y]
            for dx,dy in pairs[cur]:
                nx,ny = x+dx,y+dy
                if nx<0 or nx>=m or ny<0 or ny>=n:
                    continue
                nxt = grid[nx][ny]
                if (-dx,-dy) in pairs[nxt]:
                    g[i].append(nx*n+ny)
        
        visited = [0]*tot
        def dfs(indx):
            if indx == tot-1:
                return True
            ans = False
            visited[indx] = 1
            for nxt in g[indx]:
                if visited[nxt] == 0:
                    ans |= dfs(nxt)
            return ans
        
        return dfs(0)

if __name__ == "__main__":
    s = Solution()
    grid = [[2,4,3],[6,5,2]]
    print(s.hasValidPath(grid))
