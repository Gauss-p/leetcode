from typing import List
from functools import cache

class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()
        @cache
        def dfs(i, j):
            if j < 0:
                return 0
            if i < 0:
                return 10**18
            res = dfs(i-1, j)
            pos, limit = factory[i]
            dist = 0
            for k in range(1, min(j+1, limit)+1):
                dist += abs(robot[j-k+1]-pos)
                res = min(res, dfs(i-1, j-k)+dist)
            return res
        return dfs(len(factory)-1, len(robot)-1)

if __name__ == "__main__":
    s = Solution()
    robot = [0,4,6]
    factory = [[2,2],[6,2]]
    print(s.minimumTotalDistance(robot, factory))
