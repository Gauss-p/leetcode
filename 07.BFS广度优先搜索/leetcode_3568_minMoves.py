from typing import List

class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        # 题目要求学生从给定的初始位置开始移动，并在经过移动后拾取所有的垃圾，因此可以用bfs的思路，从最初的位置开始，每次向四个方向移动，得到新的位置和新位置对应的能量。但需要注意的是，在bfs算法中，一个状态不仅需要靠位置和能量确定，还需要靠已经拾取了哪些垃圾来确定，故需要准确标识当前状态下已经拾取了哪些垃圾，为了进行这个标识，则需要给每个垃圾位置分配一个二进制位，这样，即可通过一个二进制数字表示已经拾取的垃圾是哪些。
        # 如果不用二进制位进行标识当前已经拾取的垃圾，很可能将两条完全不同的拾取路径记为同一个状态，可能导致计算出错或重复计算，因此在标记是否访问过的矩阵visited中同样需要加上一维，用索引对应的二进制表示已经拾取的垃圾
        m, n = len(classroom), len(classroom[0])
        sx, sy = 0, 0
        cnt = 0
        litter = [[0]*n for _ in range(m)] # 每个有垃圾的位置都分配一个独有的二进制位，方便之后用或运算更新状态
        for i in range(m):
            for j in range(n):
                c = classroom[i][j]
                if c == 'S':
                    sx, sy = i, j
                if c == 'L':
                    litter[i][j] = (1<<cnt)
                    cnt += 1

        if cnt == 0:
            return 0

        res = 0
        full = (1<<cnt)-1
        dirs = [(0,1), (0,-1), (1,0), (-1,0)]
        # 总共需要四维
        visited = [[[[False]*(1<<cnt) for _ in range(energy+1)] for _ in range(n)] for _ in range(m)]
        visited[sx][sy][energy][0] = True
        q = [(sx, sy, energy, 0)]
        while q:
            tmp = q
            q = []
            for x,y,e,l in tmp:
                if l == full:
                    return res
                if e == 0:
                    continue

                for dx,dy in dirs:
                    nx, ny = x+dx, y+dy
                    if nx<0 or nx>=m or ny<0 or ny>=n or classroom[nx][ny]=='X':
                        continue
                    
                    curEnergy = e-1
                    if classroom[nx][ny] == 'R':
                        curEnergy = energy
                    curL = l | litter[nx][ny]

                    # 在循环时利用visited剪枝可以加快运算速度
                    if visited[nx][ny][curEnergy][curL] == False:
                        visited[nx][ny][curEnergy][curL] = True
                        q.append((nx, ny, curEnergy, curL))
            # q = tmp.copy()
            res += 1
        return -1

if __name__ == "__main__":
    s = Solution()
    classroom = ["S.", "XL"]
    energy = 2
    print(s.minMoves(classroom, energy))
