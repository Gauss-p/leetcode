class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        val = {'(':1, ')':-1}
        def check(cur):
            cnt = 0
            for i in cur:
                cnt += val.get(i, 0)
                if cnt < 0:
                    return False
            return cnt==0
        
        q = [s]
        while q:
            nq = set()
            res = []
            for i in q:
                if check(i):
                    res.append(i)
                if len(res):
                    continue
                    
                for indx in range(len(i)):
                    nq.add(i[:indx]+i[indx+1:])
            if len(res):
                return res
            q = list(nq)
        return []

if __name__ == "__main__":
    sl = Solution()
    s = "()())()"
    print(sl.removeInvalidParentheses(s))
