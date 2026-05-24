from typing import List
from functools import cache

class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        @cache
        def dfs(indx):
            ans = 1
            for nxt in range(indx-1, max(0, indx-d)-1, -1): # 向左跳
                if arr[nxt] >= arr[indx]: # 保证下标在[nxt,indx-1]之间的所有值都小于arr[indx]
                    break
                ans = max(ans, dfs(nxt)+1)

            for nxt in range(indx+1, min(indx+d, n-1)+1): # 向右跳
                if arr[nxt] >= arr[indx]: # 保证下标在[indx+1,nxt]之间的所有值都小于arr[indx]
                    break
                ans = max(ans, dfs(nxt)+1)

            return ans
        return max(dfs(i) for i in range(n))

if __name__ == "__main__":
    s = Solution()
    arr = [6,4,14,6,8,13,9,7,10,6,12]
    d = 2
    print(s.maxJumps(arr, d))
