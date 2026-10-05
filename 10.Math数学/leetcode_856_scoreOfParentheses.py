class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        # 利用乘法分配律对每一个最内部的括号进行统计即可
        val = {'(':1, ')':-1}
        res = 0
        cnt = 0
        for i in range(len(s)):
            if i>0 and s[i-1] == '(' and s[i] == ')':
                res += 2**(cnt-1)
            cnt += val[s[i]]
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "(())"
    print(sl.scoreOfParentheses(s))
