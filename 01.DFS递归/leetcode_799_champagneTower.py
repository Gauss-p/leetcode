from functools import cache

class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        # 定义dfs(i,j)计算第i行第j列的杯子总共接到多少杯香槟，可以发现，这个位置的杯子可以接到从左上和右上两个位置的杯子流出来的香槟，而一个位置(x,y)在两侧流出来的香槟实际上就是：(max(dfs(x,y)-1, 0))/2，其中如果这个杯子流经的总共香槟量都不足一杯，那么就不会往下流，因此取0
        # 最后即可得到：dfs(i,j) = (max(dfs(i-1,j-1)-1, 0))/2 + (max(dfs(i-1,j)-1, 0))/2，其中当j>0时才说明有左上侧的杯子，计算第一项，当j<i时才说明有右上侧的杯子，计算第二项
        # 递归基即为：当i=0,j=0时，流经的香槟总量为poured
        @cache
        def dfs(i, j):
            if i == 0 and j == 0:
                return poured
            
            left = max(dfs(i-1, j-1)-1, 0)/2 if j>0 else 0
            right = max(dfs(i-1, j)-1, 0)/2 if j<i else 0
            return left+right
        
        res = dfs(query_row, query_glass)
        return min(res, 1)

if __name__ == "__main__":
    s = Solution()
    poured, query_row, query_glass = 2, 1, 1
    print(s.champagneTower(poured, query_row, query_glass))
