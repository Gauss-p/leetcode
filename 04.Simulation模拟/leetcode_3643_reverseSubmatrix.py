from typing import List

class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        for i in range(k//2):
            row1, row2 = x+i, x+k-i-1
            lst1, lst2 = grid[row1][y:y+k], grid[row2][y:y+k]
            grid[row1] = grid[row1][:y]+lst2+grid[row1][y+k:]
            grid[row2] = grid[row2][:y]+lst1+grid[row2][y+k:]
        return grid

if __name__ == "__main__":
    s = Solution()
    grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    x, y, k = 1, 0, 3
    print(s.reverseSubmatrix(grid, x, y, k))
