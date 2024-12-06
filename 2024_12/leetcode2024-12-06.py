from typing import List

class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        x, y = 0, 0
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    x, y = i, j
                    break
        directions = [[0,-1],[0,1],[1,0],[-1,0]]
        res = 0
        for dx,dy in directions:
            nx,ny = x+dx,y+dy
            while (nx>=0 and nx<8) and (ny>=0 and ny<8):
                if board[nx][ny] == 'B':
                    break
                if board[nx][ny] == 'p':
                    res += 1
                    break
                nx,ny = nx+dx,ny+dy
        return res

if __name__ == "__main__":
    s = Solution()
    board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
    print(s.numRookCaptures(board))
