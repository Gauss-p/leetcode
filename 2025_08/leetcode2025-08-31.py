from typing import List

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        # 用dfs的方式，对每一个空白位置进行尝试各个数字，一直到试出一个合法的答案为止，这时就可以返回了
        # 那么首先我们要求出所有空白的位置，那么可以将board中所有元素循环一遍，将'.'对应的索引(i,j)数对加入一个列表space中，这样，在dfs中，确定一个位置就只需要一个在space中的索引了
        # 接下来，为了让在(i,j)中填入的数字digit合法，我们就需要知道第i行中是否出现了数字digit，第j列中是否出现了数字digit，以及(i,j)所在的3x3矩阵中是否出现了数字digit。因此我们需要先对board进行预处理，用3个列表分别判断行、列、3x3矩阵中是否出现某个数字，即row, col, block。其中，row，col均为二维列表，block为三维列表，并且row[i][digit]表示第i行中是否出现了digit，如果是，那么其值为1，否则为0，同理，col[j][digit]表示第j列中是否出现了digit，并且board[i//3][j//3][digit]表示位置(i,j)所在的3x3矩阵中是否出现了digit
        # 因此，假如要在(i,j)中填入digit，首先要满足row[i][digit]=0, col[j][digit]=0, board[i//3][j//3][digit]=0这三个条件。最后在填入以后需要注意更新row[i][digit], col[j][digit], board[i//3][j//3][digit]的值为1
        space = []
        valid = False
        def dfs(pos):
            nonlocal valid
            if pos == len(space):
                valid = True
                return
            
            i, j = space[pos]
            for digit in range(1, 10):
                if row[i][digit]==0 and col[j][digit]==0 and block[i//3][j//3][digit]==0:
                    row[i][digit] = 1
                    col[j][digit] = 1
                    block[i//3][j//3][digit] = 1

                    board[i][j] = str(digit) # 更新矩阵
                    dfs(pos+1)

                    # 恢复现场 
                    row[i][digit] = 0
                    col[j][digit] = 0
                    block[i//3][j//3][digit] = 0
                if valid:
                    return

        row = [[0]*10 for _ in range(9)] # 预处理
        col = [[0]*10 for _ in range(9)]
        block = [[[0]*10 for _ in range(3)] for _ in range(3)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    space.append((i,j))

                else:
                    digit = int(board[i][j])
                    row[i][digit] = 1
                    col[j][digit] = 1
                    block[i//3][j//3][digit] = 1
        
        dfs(0)

if __name__ == "__main__":
    s = Solution()
    board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    s.solveSudoku(board)
    for i in board:
        print(" ".join(i))
