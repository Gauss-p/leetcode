from typing import List

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        x, y = 0, 0
        curDir = 0
        limitPos = set(tuple(i) for i in obstacles)
        
        res = 0
        for op in commands:
            if op == -1:
                curDir = (curDir+1)%4
            elif op == -2:
                curDir = (curDir-1)%4
            else:
                dx, dy = dirs[curDir]
                for i in range(op):
                    if (x+dx, y+dy) in limitPos:
                        break
                    x += dx
                    y += dy
            res = max(res, x*x+y*y)
        return res

if __name__ == "__main__":
     s = Solution()
     commands = [4,-1,3]
     obstacles = []
     print(s.robotSim(commands, obstacles))
