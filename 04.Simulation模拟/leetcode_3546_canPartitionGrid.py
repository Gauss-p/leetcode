from typing import List

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        tot = sum(sum(r) for r in grid)
        def calc(grid):
            s = 0
            for r in grid:
                s += sum(r)
                if s*2 == tot:
                    return True
            return False
        return calc(grid) or calc(list(zip(*grid)))

if __name__ == "__main__":
    s = Solution()
    grid = [[1,4],[2,3]]
    print(s.canPartitionGrid(grid))
