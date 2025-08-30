from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isValidBlock(i0, j0, i1, j1): # 判断一个以(i0,j0)为左上角，以(i1,j1)为右下角的矩形是否符合要求，这样我们只需要传入九个行、九个列、九个矩阵的左上和右下坐标，分别判断即可
            cnt = [0]*10
            for i in range(i0, i1+1):
                for j in range(j0, j1+1):
                    if board[i][j] == '.':
                        continue
                    cur = int(board[i][j])
                    cnt[cur] += 1
                    if cnt[cur] == 2:
                        return False
            return True
        
        res = True
        for i in range(9):
            res = res and isValidBlock(i, 0, i, 8)
            res = res and isValidBlock(0, i, 8, i)
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                res = res and isValidBlock(i, j, i+2, j+2)
        return res

if __name__ == "__main__":
    s = Solution()
    board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    print(s.isValidSudoku(board))
