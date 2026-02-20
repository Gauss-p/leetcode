from typing import List
from functools import cache

class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        mymax = lambda x,y : x if x>y else y
        mymin = lambda x,y : x if x<y else y
        n = len(piles)
        # 定义dfs函数，dfs(x,y)返回值为:在[0...x]中的索引对应的栈中取y次，所能够取得的最大面值之和
        # 那么该值有两种情况，第一种是不选x栈中的元素，那么其值为dfs(x-1, y)，第二种是选x栈中的元素，假设在x栈中选[0...i]对应的元素，并且记录这些元素的和tmp，那么dfs(x,y)的值就是dfs(x-1, y-i-1)+tmp，循环i的所有可能值并记录dfs(x,y)的最大值即可
        # 最终答案即为dfs(n-1, k)
        @cache
        def dfs(x, y):
            if x < 0:
                return 0
            ans = dfs(x-1, y)
            tmp = 0
            for i in range(0, mymin(y, len(piles[x]))):
                tmp += piles[x][i]
                ans = mymax(ans, dfs(x-1, y-i-1)+tmp)
            return ans
        return dfs(n-1, k)

if __name__ == "__main__":
    s = Solution()
    piles = [[1,100,3],[7,8,9]]
    k = 2
    print(s.maxValueOfCoins(piles, k))
