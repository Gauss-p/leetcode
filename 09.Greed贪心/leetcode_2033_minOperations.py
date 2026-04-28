from typing import List
from collections import defaultdict

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        cnt = defaultdict(int)
        lst = []
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                a = grid[i][j]
                lst.append(a)
                cnt[a%x] = 1
                if len(cnt) == 2:
                    return -1
        lst.sort()
        # 贪心，变成中间大小的一定花费更少
        target = lst[len(lst)//2]
        return sum(abs(target-a) for a in lst)//x

if __name__ == "__main__":
    s = Solution()
    grid = [[2,4],[6,8]]
    x = 2
    print(s.minOperations(grid, x))
