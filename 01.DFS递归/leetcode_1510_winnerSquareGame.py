from functools import cache
from math import sqrt

class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        # 如果当前玩家选某个平方数时下一个玩家无论如何都是输的，那么当前玩家就可以赢；反之，如果当前玩家选任何平方数下一个玩家都可以赢，那么当前玩家就是输的。需要注意的是，如果当前剩余石子总数是平方数，那么该玩家一定可以赢，同时，如果剩余石子为0，那么该玩家一定是输的。
        @cache
        def dfs(left):
            if left == 0:
                return False
            mx = int(sqrt(left))
            if mx**2 == left:
                return True

            ans = False
            for i in range(1, mx+1):
                ans |= (not dfs(left-i**2))
            return ans
        return dfs(n)

if __name__ == "__main__":
    s = Solution()
    n = 2
    print(s.winnerSquareGame(n))
