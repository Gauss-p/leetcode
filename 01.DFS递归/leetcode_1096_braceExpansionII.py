class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        # 题目列举了很多种情况，但实际上要做的只是在每一个花括号中选择一个元素，将它们连接起来即可，只需求出所有能够得到的结果，按顺序存在一个列表中就得到了答案。
        # 或者更直白地说，如果将给出的表达式中所有花括号对替换成小括号对，并将所有的逗号替换成加号，此时按照多项式乘法的计算方式将整个式子算出来并去重即可得到答案，唯一和正常多项式运算不同的是，此处运算出来之后，就算是同样的字母相乘得到的结果，只要顺序不同，就需要算另一个答案。
        # 举个例子,对于expression="{a,b}{c,{d,e}}",先转换成多项式,得到:"(a+b)(c+(d+e))",计算可得答案为:
        # ac+ad+ae+bc+bd+be,去重分离即可得到答案
        def dfs(exp):
            right = exp.find('}')
            if right == -1:
                return set([exp])

            left = right-1
            while exp[left] != '{':
                left -= 1
            a, c = exp[:left], exp[right+1:]
            b = exp[left+1:right].split(',')

            res = set()
            for bi in b:
                res = res.union(dfs(a+bi+c))
            return res
        return sorted(dfs(expression))

if __name__ == "__main__":
    s = Solution()
    expression = "{a,b}{c,{d,e}}"
    print(s.braceExpansionII(expression))
