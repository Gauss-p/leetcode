class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        # n表示剩余可选左括号数量，cnt表示已选的左括号减右括号数量。根据括号配对的规则，在构造括号字符串时必须保证cnt大于等于0，分以下三种情况考虑：
        #   1.若n=0，则说明此时已经没有左括号可以选择，只剩下右括号，那么直接将剩余所有右括号连起来返回即可；
        #   2.若n>0，说明有左括号可选，那么就用一个左括号，后面加上剩余所有括号能够组成的括号组合，加入答案；
        #   3.若cnt>0，说明此处可选右括号，那么就用一个右括号，后面加上剩余所有括号能够组成的括号组合，加入答案；
        def dfs(n, cnt):
            if n == 0:
                return [')'*cnt]
            res = []
            nxt = dfs(n-1, cnt+1)
            for i in nxt:
                res.append('('+i)
            if cnt > 0:
                nxt = dfs(n, cnt-1)
                for i in nxt:
                    res.append(')'+i)
            return res
        return dfs(n, 0)

if __name__ == "__main__":
    s = Solution()
    n = 3
    print(s.generateParenthesis(n))
