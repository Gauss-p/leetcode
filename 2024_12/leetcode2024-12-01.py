class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        # queens用来存储每一行上皇后的位置，而makeBoard函数就是将queens中的数据整合成为一个棋盘
        def makeBoard():
            board = []
            for i in range(n):
                row[queens[i]] = 'Q' # 将当前行中被标记为皇后的位置设为'Q'，加入棋盘列表中
                board.append(''.join(row))
                row[queens[i]] = '.' # 然后再恢复初始状态，等待下一行的数据
            return board

        # 接下来的setQueens则是用递归的方式求出皇后的每一种排列方式
        def setQueens(rowIndex: int):
            if rowIndex == n:
                # 递归基，如果rowIndex已经为n，说明每一行的位置都已计算完，故求出棋盘排列，加入答案
                tmpBoard = makeBoard()
                solutions.append(tmpBoard)
                return
            for i in range(n):
                if (i in col) or (rowIndex-i in diagonal1) or (rowIndex+i in diagonal2):
                    # i用来循环当前行的皇后位置，如果i在之前已经出现，那么不能进行循环
                    # 接下来还需判断对角线，我们发现，从左上到右下的对角线上所有位置[i][j]，i-j都是定值，而从右上到坐下的对角线上所有位置[i][j]，i+j都是定值，所以如果rowIndex-i或rowIndex+i的值之前已经出现过，就说明当前位置和之前的某个位置在同一条对角线上，会攻击，因此跳过
                    continue
                queens[rowIndex] = i
                col.add(i)
                diagonal1.add(rowIndex-i)
                diagonal2.add(rowIndex+i)
                # 以上操作是将当前位置加入已选择的位置之中
                setQueens(rowIndex+1)
                col.remove(i)
                diagonal1.remove(rowIndex-i)
                diagonal2.remove(rowIndex+i)
                # 恢复现场

        solutions = []
        queens = [-1]*n
        col = set()
        diagonal1 = set()
        diagonal2 = set()
        row = ['.']*n
        # 从第0行开始填
        setQueens(0)
        return solutions

if __name__ == "__main__":
    s = Solution()
    n = 4
    print(s.solveNQueens(n))
