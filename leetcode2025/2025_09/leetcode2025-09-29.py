from typing import List
from functools import cache

class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        # 定义dfs(i,j)用来计算将索引在[i,j]中的所有顶点剖分能够得到的最小得分，那么对于每一组传入的i,j，我们都在[i+1,j-1]中选择一个索引k，表示第三个点，并将(i,k,j)这三个点分出一个三角形，得分即为values[i]*values[k]*values[j]，再加上将[i,k]分割和将[k,j]分割可以得到的最小得分，就是这种方案对应的得分了，最后对所有得分取最小值即可
        @cache
        def dfs(i, j):
            if i+1 == j:
                return 0
            ans = float("inf")
            for k in range(i+1, j):
                cur = dfs(i, k)+dfs(k, j)+values[i]*values[j]*values[k]
                if cur < ans:
                    ans = cur
            return ans
        return dfs(0, len(values)-1)

if __name__ == "__main__":
    s = Solution()
    values = [1,2,3]
    print(s.minScoreTriangulation(values))
