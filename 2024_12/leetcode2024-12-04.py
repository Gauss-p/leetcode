class Solution:
    def calculate_moves(self, direct, pos):
        # 记录当前点的所有有效移动位置，用moves保存，其中存放的是五元组。五元组中，第一个和第二个元素表示当前点的初始坐标x和y，第三个和第四个元素表示当前点的移动方向dx和dy，第五个元素表示点(x,y)朝方向(dx,dy)移动了多少次，用step表示
        # 每一个点可以移动的方向已经在主函数中初始化完成了，在这个函数中，只需要遍历所有的方向(dx,dy)，并且从起始点pos(x,y)出发，每次将x和y分别加上dx和dy，获得一个新的点，并将step加1，同时把所有在边界以内的点按照五元组的格式加入moves列表中即可
        x, y = pos[0], pos[1]
        moves = [(x, y, 0, 0, 0)]
        for dx, dy in direct:
            nx, ny = x+dx, y+dy # 新的坐标
            step = 1 # 因为从nx,ny开始就已经是走了1步了，所以step应该从1开始计数
            while (nx >= 1 and nx <= 8) and (ny >= 1 and ny <= 8):
                moves.append((x, y, dx, dy, step)) # 将区域内的点加入列表
                # 更新下一个点
                nx += dx
                ny += dy
                step += 1
        return moves

    def is_valid(self, m1, m2):
        # m1和m2分别表示两个点的移动方式，同样都是五元组，当前函数用来判断m1和m2是否会在移动过程中重合，我们可以按照m1和m2中所记录的移动方式，从(x1,y1)和(x2,y2)同时出发，每次递增(dx1,dy1)和(dx2,dy2)，如果发现(x1,y1)和(x2,y2)已经重合，说明这两种移动方式已经无效
        x1, y1, dx1, dy1, step1 = m1
        x2, y2, dx2, dy2, step2 = m2
        for i in range(max(step1, step2)):
            # 依次递增
            if i < step1:
                x1, y1 = x1+dx1, y1+dy1
            if i < step2:
                x2, y2 = x2+dx2, y2+dy2
            if x1==x2 and y1==y2:
                # 如果重合，返回false，表示这两种移动方式会重合
                return False
        return True

    def countCombinations(self, pieces: list[str], positions: list[list[int]]) -> int:
        rook_dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        bishop_dir = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
        all_dirs = {'rook':rook_dir, 'bishop':bishop_dir, 'queen':rook_dir+bishop_dir}
        # 以上所有操作用来初始化三种棋子的所有移动方向，其中queen可以直接利用现成的两个方向列表相加
        all_moves = []
        for s, p in zip(pieces, positions):
            # 计算出每一个点的所有可能移动
            all_moves.append(self.calculate_moves(all_dirs[s], p))

        n = len(pieces)
        res = 0
        paths = [None]*n # 在下面的dfs中记录每一个点的移动方式，以便判断是否会出现重合
        def dfs(i):
            if i == n:
                # 如果i=n，那么说明棋子0到棋子n-1都已经选好移动方式，并且保证不会出现重合的情况，那么答案加1
                nonlocal res
                res += 1
                return
            for m2 in all_moves[i]:
                # 用m2循环棋子i所有可能的移动方式，只要发现和之前的所有确定下来的移动方式都不会重合，那么就继续判断下一个棋子该怎么走
                if all(self.is_valid(m1, m2) for m1 in paths[:i]):
                    paths[i] = m2
                    dfs(i+1)
        dfs(0) # 从第0个棋子开始选择位置
        return res

if __name__ == "__main__":
    s = Solution()
    pieces = ["rook", "rook"]
    positions = [[1,1],[8,8]]
    print(s.countCombinations(pieces, positions))
