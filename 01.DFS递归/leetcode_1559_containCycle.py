from typing import List

class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        tot = m*n
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        visited = [0]*tot

        def dfs(indx, pa):
            if visited[indx] == 1:
                return True

            ans = False
            visited[indx] = 1
            x, y = indx//n, indx%n
            for dx, dy in dirs:
                nx, ny = x+dx, y+dy
                if nx < 0 or nx >= m or ny < 0 or ny >= n:
                    continue
                nIndx = nx*n+ny
                if grid[nx][ny] == grid[x][y] and nIndx != pa:
                    ans |= dfs(nIndx, indx)
            return ans

        for i in range(tot):
            if visited[i] == 0:
                res = dfs(i, -1)
                if res:
                    return True
        return False

if __name__ == "__main__":
    s = Solution()
    grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
    print(s.containsCycle(grid))
