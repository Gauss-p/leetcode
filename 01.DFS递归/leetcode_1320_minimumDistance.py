from functools import *

class Solution:
    def minimumDistance(self, word: str) -> int:
        n = len(word)
        pos = []
        for i in range(26):
            pos.append((i//6, i%6))
        
        @cache
        def dfs(finger1, finger2, indx):
            if indx == n:
                return 0
            ans = float("inf")
            cur = ord(word[indx])-ord('A')
            dis1 = 0 if finger1<0 else abs(pos[finger1][0]-pos[cur][0])+abs(pos[finger1][1]-pos[cur][1])
            dis2 = 0 if finger2<0 else abs(pos[finger2][0]-pos[cur][0])+abs(pos[finger2][1]-pos[cur][1])
            ans = min(ans, dis1+dfs(cur, finger2, indx+1))
            ans = min(ans, dis2+dfs(finger1, cur, indx+1))
            return ans
        res = dfs(-1, -1, 0)
        dfs.cache_clear()
        return res

if __name__ == "__main__":
    s = Solution()
    word = "CAKE"
    print(s.minimumDistance(word))
