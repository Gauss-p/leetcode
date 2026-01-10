from functools import cache

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        # 定义dfs(i,j)计算：s1[i:]和s2[j:]中能够匹配的最大字符总和，这样，如果我们求出s1[i:]和s2[j:]中所有字符的ASCII总和，减去dfs(i,j)就可以得到最小的ASCII删除和。为了计算dfs(i,j)，可以分以下两种情况：1.不选s1[i]和s2[j]匹配；2.选择s1[i]和s2[j]匹配(当且仅当s1[i]=s2[j]时)。对于情况1，我们就需要跳过当前位置，但由于有两个索引，因此跳过之后可以是dfs(i+1,j)或dfs(i,j+1)，对于情况2，我们既然已经选择当前位置匹配，那么后面就剩下dfs(i+1,j+1)了
        n, m = len(s1), len(s2)
        tot = 0
        for i in s1+s2:
            tot += ord(i)
        @cache
        def dfs(i, j):
            if i == n or j == m:
                return 0
            res1 = dfs(i+1, j)
            res2 = dfs(i, j+1)
            res3 = 0
            if s1[i] == s2[j]:
                res3 = ord(s1[i])*2 + dfs(i+1, j+1)
            return max(res1, res2, res3)
        
        return tot-dfs(0, 0)

if __name__ == "__main__":
    s = Solution()
    s1 = "sea"
    s2 = "eat"
    print(s.minimumDeleteSum(s1, s2))
