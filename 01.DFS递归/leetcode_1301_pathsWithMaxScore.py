from typing import List
from functools import *

class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        modNum = 1_000_000_007
        n = len(board)
        dirs = [(0,-1), (-1,0), (-1,-1)]
        @cache
        def dfs(x, y):
            if x == 0 and y == 0:
                return (0, 1)
            maxScore = -10**18
            cnt = 0
            v = int(board[x][y]) if (x,y)!=(n-1,n-1) else 0
            for dx,dy in dirs:
                nx, ny = x+dx, y+dy
                if nx<0 or ny<0 or board[nx][ny] == 'X':
                    continue
                curScore, scoreNum = dfs(nx,ny)
                if curScore == -10**18:
                    continue
                curScore += v
                if curScore > maxScore:
                    maxScore = curScore
                    cnt = scoreNum
                elif curScore == maxScore:
                    cnt = (cnt+scoreNum)%modNum
            return (maxScore, cnt)
        
        res = list(dfs(n-1, n-1))
        if res[0] == -10**18:
            return [0,0]
        return res

if __name__ == "__main__":
    s = Solution()
    board = ["E23","2X2","12S"]
    print(s.pathsWithMaxScore(board))
