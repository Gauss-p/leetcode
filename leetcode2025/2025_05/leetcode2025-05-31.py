from typing import List
from collections import deque

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        # 因为我们需要按照标号来移动，而在给出的board列表中，我们只能依靠索引来确定位置，所以首先我们需要定义一个函数将给出的标号x来求出board中对应的索引。可以发现，题目给出的标号是在顺序排列的基础上首先将所有数字加1，然后将奇数行左右翻转，再将所有列上下翻转。
        # 按照这个规律，如果已知一个标号，我们先将它减1，然后求出它在顺序排列时的位置(row,col)，接着按照标号转换的步骤进行转换，首先，如果row是奇数，那么将col变为翻转后的位置n-1-col，否则不变化，然后将row变为翻转后的位置n-1-row，即可得到该标号在board中对应的位置

        # 函数主体用BFS的方法实现，对于每一次取出的节点cur和到达cur的步数dis，将cur所有的可跳转标号tmp_nxt遍历一遍，根据题目，如果tmp_nxt在board中对应的数字不是-1，那么cur就可以通过tmp_nxt跳转到tmp_nxt在board中对应的那个标号，否则cur只能跳转到tmp_nxt。这里为了跳过一些循环，我们可以直接判断，如果cur可以跳转到的标号是n**2，那么直接返回dis+1即可，否则就将二元组加入队列中再次计算即可
        # 这里还需要用visited避免重复访问

        n = len(board)
        def get_pos(x):
            x -= 1
            row = x//n
            col = x%n
            if row&1: # 如果row为奇数，就将col变为反转后的位置
                col = n-1-col
            row = n-1-row # 无论如何都直接将row变为反转后的位置
            return [row, col]
        
        q = deque([(1,0)])
        visited = [0]*(n*n)
        while q:
            cur, dis = q.popleft() # 取出当前节点和到达该节点的距离
            # 防止重复计算
            if visited[cur]:
                continue
            visited[cur] = 1
            for tmp_nxt in range(cur+1, min(n*n, cur+6)+1):
                x,y = get_pos(tmp_nxt)
                nxt = tmp_nxt # 确定通过tmp_nxt可以到达哪个节点
                if board[x][y] != -1:
                    nxt = board[x][y]
                if nxt == n*n: # 跳过中间的循环
                    return dis+1
                q.append((nxt, dis+1))
        return -1

if __name__ == "__main__":
    s = Solution()
    board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
    print(s.snakesAndLadders(board))
