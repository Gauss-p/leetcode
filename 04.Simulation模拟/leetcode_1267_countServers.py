class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        s1 = list(map(sum, grid))
        s2 = list(map(sum, list(zip(*grid))))
        return sum((grid[i][j]==1 and (s1[i]>1 or s2[j]>1)) for i in range(m) for j in range(n))

if __name__ == "__main__":
    s = Solution()
    grid = [[1,0],[0,1]]
    print(s.countServers(grid))
