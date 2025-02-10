from typing import List
from collections import deque

HOLE, MOUSE_START, CAT_START = 0, 1, 2
MOUSE_TURN, CAT_TURN = 0, 1
UNKNOWN, MOUSE_WIN, CAT_WIN = 0, 1, 2

class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        n = len(graph)
        # 定义degrees数组来存储每一种状态的度数。初始时，每个状态的度表示该状态的移动方可以移动到的结点数，然后就要删除掉所有猫移动到0的情况，即对于0的所有相邻节点，都将其移动方为猫的所有状态的度数减1，表示去掉一种移动的可能。在做完这些初始化操作之后，每遇到一个必败状态就将该状态的度数减1，直到减为0，此时就可以直接将其对应的初始情况的胜败情况放到当前状态
        degrees = [[[0, 0] for _ in range(n)] for _ in range(n)]
        # 定义results数组用来存储每一种状态的胜败情况。在初始化时，就要将每一种基础情况都先保存下来。共有两种基础情况，第一种是猫和老鼠位置相同，此时定义为猫赢，第二种是老鼠到达了洞的位置，此时老鼠赢
        results = [[[0, 0] for _ in range(n)] for _ in range(n)]
        # 初始化所有状态的度数
        for i in range(n):
            for j in range(1, n):
                degrees[i][j][MOUSE_TURN] = len(graph[i])
                degrees[i][j][CAT_TURN] = len(graph[j])
        # 删除与洞连接的猫的位置的度数
        for i in range(n):
            for j in graph[HOLE]:
                degrees[i][j][CAT_TURN] -= 1
        
        # =========================
        q = deque()
        # 初始化边界情况
        for i in range(1, n):
            # 对于猫和老鼠位置相同的状态，无论是轮到谁走，结果都是猫赢
            results[i][i][MOUSE_TURN] = CAT_WIN
            results[i][i][CAT_TURN] = CAT_WIN
            # 在确定了一种情况后，就将该情况加入队列中
            q.append((i, i, MOUSE_TURN))
            q.append((i, i, CAT_TURN))
        for j in range(1, n):
            # 对于老鼠到达洞的状态，无论是轮到谁走，结果都是老鼠赢
            results[HOLE][j][MOUSE_TURN] = MOUSE_WIN
            results[HOLE][j][CAT_TURN] = MOUSE_WIN
            # 在确定了一种情况后，就将该情况加入队列中
            q.append((HOLE, j, MOUSE_TURN))
            q.append((HOLE, j, CAT_TURN))
        
        # 在求解答案时，我们采用的是自底向上的计算方法，首先在队列中取出一个已经有确定结果的情况，然后根据题目所给出的graph计算出所有前一种情况的可能(为了方便，下面将‘前一种情况’称为‘前情况’，将‘已经有确定结果的情况’称为‘确定情况’)，遍历所有的"前情况"，如果该"前情况"还没有保存答案，就进行计算。首先是必胜情况，如果"确定情况"的赢家和遍历到的"前情况"的移动者相同，我们就可以认为当前的"前情况"的赢家就是"确定情况"的赢家，此时记录答案并将其加入确定答案的状态的队列q中。接下来是非胜的情况，对于每一个非胜的"前情况"，都将其度数减1，如果减到了0，那么直接将"确定情况"的答案作为该"前情况"的答案即可
        while q:
            state = q.popleft()
            mouse, cat, turn = state # 取出一个"确定情况"
            prevStates = self.getPrevStates(mouse, cat, turn, graph) # 得到所有的"前情况"
            cur_res = results[mouse][cat][turn] # 便于书写，我们将cur_res先取出
            for p in prevStates:
                prevMouse, prevCat, prevTurn = p # 取出一个"前情况"
                if results[prevMouse][prevCat][prevTurn] == UNKNOWN:
                    winState = (cur_res==MOUSE_WIN and prevTurn==MOUSE_TURN) or (cur_res==CAT_WIN and prevTurn==CAT_TURN)
                    # 如果winState为True，就说明当前的"前情况"是必胜情况，否则为非胜情况
                    if winState:
                        # 必胜情况
                        results[prevMouse][prevCat][prevTurn] = cur_res
                        q.append((prevMouse, prevCat, prevTurn))
                    else:
                        # 非胜情况
                        degrees[prevMouse][prevCat][prevTurn] -= 1 # 如果非胜，就将度数减1
                        if degrees[prevMouse][prevCat][prevTurn] == 0:
                            # 如果减到了0，说明无论怎么走都不会胜利，那么就将"确定情况"的答案给它
                            results[prevMouse][prevCat][prevTurn] = cur_res
                            q.append((prevMouse, prevCat, prevTurn))
        return results[MOUSE_START][CAT_START][MOUSE_TURN] # 最后返回初始情况的答案即可

    def getPrevStates(self, mouse, cat, turn, graph):
        prevStates = []
        # 取出所有可能的"前情况"
        prevTurn = CAT_TURN if turn==MOUSE_TURN else MOUSE_TURN
        if prevTurn == CAT_TURN:
            # 如果前一次轮到猫，那么它需要避开洞
            for prevCat in graph[cat]:
                if prevCat != HOLE:
                    prevStates.append((mouse, prevCat, prevTurn))
        else:
            # 否则不需要避开，直接加即可
            for prevMouse in graph[mouse]:
                prevStates.append((prevMouse, cat, prevTurn))
        return prevStates

if __name__ == "__main__":
    s = Solution()
    graph = [[1,3],[0],[3],[0,2]]
    print(s.catMouseGame(graph))
