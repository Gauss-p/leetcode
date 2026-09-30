class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        # 按照入栈顺序的奇偶性将左右括号分组，即可保证恰好选一半左括号，一半右括号，即可使分出来的两个括号组深度最平均
        res = []
        cur = 0
        for i in seq:
            if i == '(':
                cur += 1
                res.append(cur%2)
            else:
                res.append(cur%2)
                cur -= 1
        return res

if __name__ == "__main__":
    s = Solution()
    seq = "(()())"
    print(s.maxDepthAfterSplit(seq))
