from typing import List
from functools import cache

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        n = len(digits)
        visited = [0]*n
        res = set()
        @cache
        # dfs函数只填3个位置，但要注意第一个位置不能填0，第三个位置必须填偶数，之后用set去重，最终转为list再排序即可
        def dfs(num, pos):
            if pos == 3:
                return set([num])
            ans = set()
            for i in range(n):
                if pos == 2 and digits[i]%2 != 0:
                    continue
                if pos == 0 and digits[i] == 0:
                    continue
                if visited[i] == 0:
                    visited[i] = 1
                    ans = ans.union(dfs(num*10+digits[i], pos+1))
                    visited[i] = 0
            return ans
        return sorted(list(dfs(0,0)))

if __name__ == "__main__":
    s = Solution()
    digits = [2,1,3,0]
    print(s.findEvenNumbers(digits))
