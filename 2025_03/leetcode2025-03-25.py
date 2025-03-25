from typing import List
from collections import defaultdict

class Solution:
    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        res = [[0]*n for _ in range(m)]
        for i in range(n):
            # 首先计算从第一行开始的对角线
            x,y = 0,i
            cnt = defaultdict(int)
            cnt[grid[x][y]] += 1
            # 用两次循环，第一次计算当前对角线上所有元素左上方的不同值的数量
            # 因为是从左上往右下循环的，所以首先移动位置，然后记录答案
            while x+1<m and y+1<n:
                x,y = x+1,y+1
                res[x][y] = len(cnt)
                cnt[grid[x][y]] += 1
            
            x,y = 0,i
            # 这第二次循环计算当前对角线上所有元素右下方的不同值数量
            # 因为是从左上往右下循环的，所以先减掉当前元素，然后和刚才记录的答案相减求绝对值即可
            while x<m and y<n:
                cnt[grid[x][y]] -= 1
                if cnt[grid[x][y]] == 0:
                    cnt.pop(grid[x][y])
                res[x][y] = abs(res[x][y]-len(cnt))
                x,y = x+1,y+1
        
        for i in range(1,m):
            # 然后计算从第一列开始的对角线，因为[0][0]开始的对角线计算过了，所以跳过
            x,y = i,0
            cnt = defaultdict(int)
            cnt[grid[x][y]] += 1
            # 同理，用两次循环，第一次计算当前对角线上所有元素左上方的不同值的数量
            while x+1<m and y+1<n:
                x,y = x+1,y+1
                res[x][y] = len(cnt)
                cnt[grid[x][y]] += 1
            
            # 第二次循环计算当前对角线上所有元素右下方的不同值数量，相减求绝对值
            x,y = i,0
            while x<m and y<n:
                cnt[grid[x][y]] -= 1
                if cnt[grid[x][y]] == 0:
                    cnt.pop(grid[x][y])
                res[x][y] = abs(res[x][y]-len(cnt))
                x,y = x+1,y+1
        return res

if __name__ == "__main__":
    s = Solution();
    grid = [[1,2,3],[3,1,5],[3,2,1]]
    print(s.differenceOfDistinctValues(grid))
