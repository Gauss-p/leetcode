from collections import defaultdict
from functools import cache

class Solution:
    def numOfWays(self, n: int) -> int:
        # 分析题目可知，每一行的总情况数是一定的，因此可以首先计算出每一行都有哪些情况，这里就可以用暴力计算，因为每个位置只有三个可能的值，且一共只有三个位置。我们可以将所有的情况保存在一个列表modes中，以便接下来模拟计算
        # 题目要求每一列中相邻元素不同，也就是说，每相邻两行中对应位置元素不能相同。但如果要模拟，在模拟中每次遍历所有情况去判断其是否能够当作下一行太慢了，所以可以先预处理每一行对应的所有合法的下一行。这里同样可以用暴力的方式，用一个字典保存下每种模式对应的下一行模式的所有情况
        # 然后开始模拟，用dfs的方式，每次均在给出的当前行的基础上遍历其对应的所有合法的下一行，然后累加答案，需要注意的是，当我们递归到最后一行时，就应当返回1作为答案
        # 最后，我们需要将第一行的所有情况传入dfs函数中计算答案，累加所有情况对应的答案数量即可
        colors = ['R','Y','G']
        modes = [] # 保存所有情况
        for a in colors:
            for b in colors:
                if b==a:
                    continue
                for c in colors:
                    if c==b:
                        continue
                    modes.append(a+b+c)
        
        m = len(modes)
        dic = defaultdict(list) # 每种情况对应的所有合法的下一行
        for i in range(m):
            a = modes[i]
            for j in range(m):
                b = modes[j]
                if i==j:
                    continue
                if a[0]!=b[0] and a[1]!=b[1] and a[2]!=b[2]:
                    dic[a].append(b)
        
        modNum = 1_000_000_007
        @cache
        def dfs(indx, cur):
            if indx == n-1:
                return 1
            ans = 0
            for nxt in dic[cur]: # 下一行所有情况
                ans = (ans+dfs(indx+1, nxt))%modNum
            return ans
        
        res = 0
        for first in modes:
            res = (res+dfs(0, first))%modNum
        return res

if __name__ == "__main__":
    s = Solution()
    n = 2
    print(s.numOfWays(n))
