from typing import List

class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        myMin = lambda x,y : x if x<y else y

        m, n = len(grid), len(grid[0])
        res = [[float("inf")]*(n-k+1) for _ in range(m-k+1)]
        for i in range(m-k+1):
            for j in range(n-k+1):
                tot = []
                for x in range(i, i+k):
                    for y in range(j, j+k):
                        tot.append(grid[x][y])
                tot.sort()

                for indx in range(len(tot)-1):
                    if tot[indx+1] != tot[indx]:
                        res[i][j] = myMin(res[i][j], tot[indx+1]-tot[indx])
                res[i][j] = 0 if res[i][j]==float("inf") else res[i][j]
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[1,8],[3,-2]]
    k = 2
    print(s.minAbsDiff(grid, k))
