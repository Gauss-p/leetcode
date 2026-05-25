from bisect import *

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        if s[-1] == '1':
            return False
        
        n = len(s)
        q = [0]
        pos = [i for i in range(1, n) if s[i]=='0']
        begin = 0
        while q:
            q2 = []
            for i in q:
                if i == n-1:
                    return True
                j = max(begin, bisect_left(pos, i+minJump))
                while j<len(pos) and pos[j]-i >= minJump and pos[j]-i <= maxJump:
                    q2.append(pos[j])
                    j += 1
                begin = j
            q = q2
        return False

if __name__ == "__main__":
    sl = Solution()
    s = "011010"
    minJump, maxJump = 2, 3
    print(sl.canReach(s, minJump, maxJump))
