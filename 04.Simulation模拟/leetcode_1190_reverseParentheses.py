class Solution:
    def reverseParentheses(self, s: str) -> str:
        # 从内层到外层，每个括号内的内容都进行反转即可
        pos = []
        for r in range(len(s)):
            if s[r] == ')':
                l = pos.pop()
                s = s[:l]+'.'+s[l+1:r][::-1]+'.'+s[r+1:]
            if s[r] == '(':
                pos.append(r)
        return s.replace('.', '')

if __name__ == "__main__":
    sl = Solution()
    s = "(u(love)i)"
    print(sl.reverseParentheses(s))
