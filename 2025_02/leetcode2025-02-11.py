from typing import List
from collections import deque

MOUSE_TURN, CAT_TURN = 0, 1
UNKNOWN, MOUSE_WIN, CAT_WIN = 0, 1, 2
MAX_MOVES = 1000
WALL, CAT, MOUSE, FOOD = '#', 'C', 'M', 'F'
dirs = ((-1, 0), (1, 0), (0, -1), (0, 1))

class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        self.__rows, self.__cols = len(grid), len(grid[0])
        self.__grid = grid
        self.__catJump, self.__mouseJump = catJump, mouseJump
        mouseStart, catStart, food = -1, -1, -1
        tot = self.__rows*self.__cols
        # 为了方便写代码，我们可以将索引[i][j]整合成一个数i*cols+j，这样所有位置就可以转化成0到rows*cols的所有数字。所以如果我们用pos在[0,tot]之间遍历，pos对应的位置就是[pos//cols][pos%cols]
        # 这道题目与猫和老鼠I不同，没有给出老鼠和猫开始的位置分别是多少，也没有给出食物的位置，所以我们首先要遍历一遍，来找出老鼠和猫开始的位置以及食物的位置
        for pos in range(tot):
            i, j = pos//self.__cols, pos%self.__cols
            c = grid[i][j]
            if c == CAT:
                catStart = pos
            elif c == MOUSE:
                mouseStart = pos
            elif c == FOOD:
                food = pos
        
        # 定义列表degrees存储所有状态的度数。一个状态的度数在最开始表示该状态的移动方所有的移动可能数，而在之后的计算中，如果一个状态的某个移动可能被确定为非胜状态，就将该状态的度数减1。如果一个状态的度数被减到了0，我们直接将它的边界状态的输赢情况放到当前状态即可
        degrees = [[[0, 0] for _ in range(tot)] for _ in range(tot)]
        # 定义列表results存储所有状态的输赢情况以及移动方所用的步数，因为有两个移动方，又要存两个数值，所以我们需要用一个四维列表来存储。results[mouse][cat][turn][0]表示当前状态的输赢情况，results[mouse][cat][turn][1]则表示turn对应的移动方的移动次数
        results = [[[[0, 0] for _ in range(2)] for _ in range(tot)] for _ in range(tot)]
        # 计算度数
        for mouse in range(tot):
            # 如果mouse和cat有一个在墙的位置，那么该情况是不合法的，跳过
            mouseRow, mouseCol = mouse//self.__cols, mouse%self.__cols
            if grid[mouseRow][mouseCol] == WALL:
                continue
            for cat in range(tot):
                catRow, catCol = cat//self.__cols, cat%self.__cols
                if grid[catRow][catCol] == WALL:
                    continue
                # 因为题目说两个玩家可以选择保持不动，所以对于每一个状态，都有可能是由上一次同样的mouse和cat位置转移过来的，因此它本身就需要算成一个度
                degrees[mouse][cat][MOUSE_TURN] += 1
                degrees[mouse][cat][CAT_TURN] += 1
                for d in dirs:
                    # 一共四个方向，每个玩家在每个方向都可以走1至最大限度步，最大限度是题目已经给定的mouseJump和catJump，所以直接遍历即可
                    # 计算老鼠
                    row, col, jump = mouseRow+d[0], mouseCol+d[1], 1
                    while 0 <= row < self.__rows and 0 <= col < self.__cols and grid[row][col] != WALL and jump<=mouseJump:
                        nextMouse, nextCat = self.getPos(row, col), self.getPos(catRow, catCol)
                        degrees[nextMouse][nextCat][MOUSE_TURN] += 1 # 可能的移动总量加1
                        row, col, jump = row+d[0], col+d[1], jump+1 # 再往后跳一步
                    # 计算猫
                    row, col, jump = catRow+d[0], catCol+d[1], 1
                    while 0 <= row < self.__rows and 0 <= col < self.__cols and grid[row][col] != WALL and jump<=catJump:
                        nextMouse, nextCat = self.getPos(mouseRow, mouseCol), self.getPos(row, col)
                        degrees[nextMouse][nextCat][CAT_TURN] += 1
                        row, col, jump = row+d[0], col+d[1], jump+1

        # 计算边界情况，一共有三种：猫鼠位置相同，猫在食物的位置或者鼠在食物的位置。对于前两种情况，无论当前轮到老鼠走还是猫走，都是猫获胜，我们将results对应的情况的输赢情况设定为猫赢，并将移动步数设定为0即可。而对于最后一种情况，是老鼠获胜，此时将输赢情况设定为老鼠赢，并将移动步数设定为0即可。而对于这些已经有确定答案的状态，直接将其加入队列q中即可
        q = deque()
        # 第一种情况，老鼠和猫在同一个位置
        for pos in range(tot):
            row, col = pos//self.__cols, pos%self.__cols
            if grid[row][col] == WALL or grid[row][col] == FOOD:
                continue
            results[pos][pos][MOUSE_TURN][0] = CAT_WIN
            results[pos][pos][MOUSE_TURN][1] = 0
            results[pos][pos][CAT_TURN][0] = CAT_WIN
            results[pos][pos][CAT_TURN][1] = 0
            q.append((pos, pos, MOUSE_TURN))
            q.append((pos, pos, CAT_TURN))
        # 第二种情况，猫在食物的位置
        for mouse in range(tot):
            mouseRow, mouseCol = mouse//self.__cols, mouse%self.__cols
            if grid[mouseRow][mouseCol] == WALL or grid[mouseRow][mouseCol] == FOOD:
                continue
            results[mouse][food][MOUSE_TURN][0] = CAT_WIN
            results[mouse][food][MOUSE_TURN][1] = 0
            results[mouse][food][CAT_TURN][0] = CAT_WIN
            results[mouse][food][CAT_TURN][1] = 0
            q.append((mouse, food, MOUSE_TURN))
            q.append((mouse, food, CAT_TURN))
        # 第三种情况，老鼠在食物的位置
        for cat in range(tot):
            catRow, catCol = cat//self.__cols, cat%self.__cols
            if grid[catRow][catCol] == WALL or grid[catRow][catCol] == FOOD:
                continue
            results[food][cat][MOUSE_TURN][0] = MOUSE_WIN
            results[food][cat][MOUSE_TURN][1] = 0
            results[food][cat][CAT_TURN][0] = MOUSE_WIN
            results[food][cat][CAT_TURN][1] = 0
            q.append((food, cat, MOUSE_TURN))
            q.append((food, cat, CAT_TURN))
        
        # 下面进入拓扑排序
        while q:
            # 首先取出一种确定答案的状态，并通过函数获取它的所有前一种状态
            state = q.popleft()
            mouse, cat, turn = state
            result = results[mouse][cat][turn][0]
            steps = results[mouse][cat][turn][1]
            prevStates = self.getPrevStates(mouse, cat, turn)
            for prevState in prevStates:
                # 以下我们称‘前一种状态’为‘前状态’，并称‘有确定答案的状态’为‘确定状态’
                prevMouse, prevCat, prevTurn = prevState
                if results[prevMouse][prevCat][prevTurn][0] == UNKNOWN:
                    # 只有在该‘前状态’没有保存过答案的时候才需要进行计算
                    winState = (result==MOUSE_WIN and prevTurn==MOUSE_TURN) or (result==CAT_WIN and prevTurn==CAT_TURN) # 判断当前‘前状态’是否为必胜状态
                    if winState:
                        # 如果是必胜状态，就将该‘前状态’的输赢情况设定为当前‘确定状态’的赢家
                        results[prevMouse][prevCat][prevTurn][0] = result
                        results[prevMouse][prevCat][prevTurn][1] = steps+1 # 因为往前推了一步，所以移动步数需要多加1
                        q.append((prevMouse, prevCat, prevTurn))
                    else:
                        # 如果不是必胜状态，就将该‘前状态’的度数减1，如果减到了0，就将当前‘确定状态’的输赢状况复制给该‘前状态’即可
                        degrees[prevMouse][prevCat][prevTurn] -= 1
                        if degrees[prevMouse][prevCat][prevTurn] == 0:
                            results[prevMouse][prevCat][prevTurn][0] = result
                            results[prevMouse][prevCat][prevTurn][1] = steps+1
                            q.append((prevMouse, prevCat, prevTurn))
        return results[mouseStart][catStart][MOUSE_TURN][0]==MOUSE_WIN and results[mouseStart][catStart][MOUSE_TURN][1]<=MAX_MOVES # 如果初始情况是老鼠赢并且老鼠的移动次数小于等于1000次，返回True，否则返回False

    def getPos(self, row, col):
        # 计算索引[row][col]对应的数字
        return row*self.__cols + col

    def getPrevStates(self, mouse, cat, turn):
        prevStates = []
        mouseRow, mouseCol = mouse//self.__cols, mouse%self.__cols
        catRow, catCol = cat//self.__cols, cat%self.__cols
        prevTurn = CAT_TURN if turn==MOUSE_TURN else MOUSE_TURN
        # 为了共用下面的代码，我们需要分两种情况来对最大移动步数和起始位置进行赋值
        maxJump = self.__mouseJump if prevTurn==MOUSE_TURN else self.__catJump
        startRow = mouseRow if prevTurn==MOUSE_TURN else catRow
        startCol = mouseCol if prevTurn==MOUSE_TURN else catCol
        prevStates.append((mouse, cat, prevTurn)) # 因为题目说双方可以选择保持不动，所以如果位置不动，并更改移动方，这就是一种‘前状态’
        for d in dirs:
            i, j, jump = startRow+d[0], startCol+d[1], 1
            while 0<=i<self.__rows and 0<=j<self.__cols and self.__grid[i][j]!=WALL and jump<=maxJump:
                # 和计算度数的时候相似，对于所有的方向，都不断移动，直到移到最大步数或超出边界
                # 因为我们想共用下面的代码，所以需要分两种移动方来计算
                prevMouseRow = i if prevTurn==MOUSE_TURN else mouseRow
                prevMouseCol = j if prevTurn==MOUSE_TURN else mouseCol
                prevCatRow = i if prevTurn==CAT_TURN else catRow
                prevCatCol = j if prevTurn==CAT_TURN else catCol
                prevMouse = self.getPos(prevMouseRow, prevMouseCol)
                prevCat = self.getPos(prevCatRow, prevCatCol)
                prevStates.append((prevMouse, prevCat, prevTurn)) # 计算完成，加入即可
                i, j, jump = i+d[0], j+d[1], jump+1
        return prevStates

if __name__ == "__main__":
    s = Solution()
    grid = ["####F","#C...","M...."]
    catJump,mouseJump = 1,2
    print(s.canMouseWin(grid, catJump, mouseJump))
