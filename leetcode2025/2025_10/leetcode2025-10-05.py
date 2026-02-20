from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # 正难则反，从和太平洋交接的所有位置开始，向中间更高的地方寻找，那么能够找到的所有点就一定都可以流到太平洋。同样，从和大西洋交界的所有位置开始，向中间更高的地方寻找，那么能够找到的所有点就一定都可以流到大西洋。最后，将两次找到的点求一个交集，就可以得到即可流向太平洋也可流向大西洋的所有点了
        m, n = len(heights), len(heights[0])
        dirs = [(0,1), (0,-1), (1,0), (-1,0)]
        pacific, atlantic = set(), set() # 分别记录访问过的所有点
        def dfs(i, j, last, visited):
            if i<0 or i>=m or j<0 or j>=n or ((i,j) in visited) or heights[i][j] < last:
                # 必须向更高的位置访问
                return
            visited.add((i,j))
            for dx,dy in dirs:
                nx, ny = i+dx, j+dy
                dfs(nx, ny, heights[i][j], visited)
        
        for j in range(n):
            dfs(0, j, -float("inf"), pacific)
            dfs(m-1, j, -float("inf"), atlantic)

        for i in range(m):
            dfs(i, 0, -float("inf"), pacific)
            dfs(i, n-1, -float("inf"), atlantic)
        return list(pacific.intersection(atlantic))

if __name__ == "__main__":
    s = Solution()
    heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    print(s.pacificAtlantic(heights))
