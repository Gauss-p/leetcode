from functools import *

class Solution:
    def rotatedDigits(self, n: int) -> int:
        s = str(n)
        choices = [0, 1, 2, 5, 6, 8, 9]
        diffSet = set([2,5,6,9])
        @cache
        def dfs(indx, isSmall, isDiff):
            if indx == len(s):
                return int(isDiff)
            ans = 0
            high = 9 if isSmall else int(s[indx])
            for cur in choices:
                if cur > high:
                    break
                ans += dfs(indx+1, (isSmall | (cur<int(s[indx]))), (isDiff | (cur in diffSet)))
            return ans
        return dfs(0, False, False)

if __name__ == "__main__":
    s = Solution()
    n = 10
    print(s.rotatedDigits(n))
