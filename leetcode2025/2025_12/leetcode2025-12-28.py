from typing import List

class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        return sum(sum((1 if x<0 else 0) for x in i) for i in grid)

if __name__ == "__main__":
    s = Solution()
    grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    print(s.countNegatives(grid))
