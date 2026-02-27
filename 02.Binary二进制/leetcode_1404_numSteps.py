class Solution:
    def numSteps(self, s: str) -> int:
        s = list(s)
        res = 0
        while len(s) and s!=['1']:
            if s[-1] == '0':
                s.pop()
            else:
                indx = len(s)-1
                while indx >= 0 and s[indx] == '1':
                    s[indx] = '0'
                    indx -= 1
                if indx >= 0:
                    s[indx] = '1'
                else:
                    s = ['1']+s
            res += 1
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "1101"
    print(sl.numSteps(s))
