from functools import cache

class Solution:
    def knightProbability(self, n: int, k: int, r: int, c: int) -> float:
        dirs = [[1,2],[1,-2],[-1,2],[-1,-2],[2,1],[2,-1],[-2,1],[-2,-1]]

        @cache
        # 定义dfs(step, x, y)返回移动step次后仍然在棋盘内的方案总数
        def dfs(step, x, y):
            if step == k:
                return 1
            res = 0
            for dx,dy in dirs:
                if x+dx>=0 and x+dx<n and y+dy>=0 and y+dy<n:
                    res += dfs(step+1, x+dx, y+dy)
            return res
                
        inside = dfs(0, r, c)
        for i in range(k):
            inside /= 8
        return inside

if __name__ == "__main__":
    s = Solution()
    n,k,r,c = 3,2,0,0
    print(s.knightProbability(n,k,r,c))
