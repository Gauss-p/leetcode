class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        val = {'(':1, ')':-1}
        cnt = 0
        res = ""
        for i in s:
            cnt += val[i]
            if (i=='(' and cnt==1) or (i==')' and cnt==0):
                continue
            res += i
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "(()())(())"
    print(sl.removeOuterParentheses(s))
