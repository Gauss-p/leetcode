from typing import List

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = []
        def dfs(cur, is_beg):
            res.append(cur)
            for i in range(is_beg, 10):
                if cur*10+i <= n:
                    dfs(cur*10+i, is_beg&0)
        dfs(0, 1)
        res.pop(0)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 13
    print(s.lexicalOrder(n))
