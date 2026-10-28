from functools import *

class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        # 由于是异或运算，不能在每一个位置都选择到(m-1,n-1)的路径最小异或值，因此需要将所有路径可能的异或值保存下来，再和当前位置的值异或，即可得到从当前点开始到(m-1,n-1)所有路径可能的异或值，一直传到(0,0)点即可
        m, n = len(grid), len(grid[0])
        @cache
        def dfs(i, j):
            if i==m-1 and j==n-1:
                return set([grid[i][j]])
            st = set()
            if i<m-1:
                for x in list(dfs(i+1, j)):
                    st.add(grid[i][j] ^ x)
            if j<n-1:
                for x in list(dfs(i, j+1)):
                    st.add(grid[i][j] ^ x)
            return st
        dfs.cache_clear()
        return min(dfs(0, 0))

if __name__ == "__main__":
    s = Solution()
    grid = [[1,2],[3,4]]
    print(s.minCost(grid))
