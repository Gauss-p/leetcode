from collections import defaultdict
from string import *

class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        # 因为题目要求“字典序最小”，所以就需要将baseStr中的每一个字符根据s1和s2的对应关系变成最小的一个字符，用并查集的思路，就相当于在每一对s1[i]和s2[i]中创建一条边，对于给出的baseStr中的每一个字符，将它替换成它所在的连通块中最小的一个字符即可
        # 那么为了方便查找最小的连通块中的字符，可以考虑将每一个节点的最高祖先都设置为连通块中的最小字符，这样每次只需调用find函数寻找最高祖先即可。为了实现这个功能，我们可以在并查集的合并函数中操作，接受两个字符x和y，先找出它们的最高祖先px和py，如果px<py，那么遵循更小的元素辈分更高的原则，我们就将py的父亲设置为px，否则就将px的父亲设置为py，这样既保证了有序又实现了合并两个元素的目的
        # 那么在计算的时候首先将每一组对应的s1[i]和s2[i]合并，求出最终的祖先列表，最后对于baseStr中的每一个字符c，将其变成find(c)，即c的最高祖先即可
        # 需要注意的是，在初始化的时候，要将每一个字符的祖先先设置为自己，而只在合并的函数中改变字符的祖先。

        pa = defaultdict(str)
        for c in ascii_lowercase:
            pa[c] = c
        def find(x):
            # 这里的find函数的写法用到了压缩树的方法来缩短查询时间，因为在每一次查找的时候，我们都将路径上的所有节点的祖先都置为这条路径上的最高祖先了
            if pa[x] != x:
                pa[x] = find(pa[x])
            return pa[x]
            # if pa[x] == x:
            #     return x
            # pa[x] = find(pa[x])
            # return pa[x]

        def union(x, y):
            px, py = find(x), find(y)
            # 下面的代码是为了实现题目要求的"字典序最小"，将小的字符的辈分排得更高
            if px > py:
                pa[px] = py
            else:
                pa[py] = px

        for i in range(len(s1)):
            # 先进行合并
            union(s1[i], s2[i])
        
        res = ""
        for c in baseStr:
            # 然后对于每一个字符只需要找到它的最高祖先即可
            res += find(c)
        return res

if __name__ == "__main__":
    s = Solution()
    s1 = "parker"
    s2 = "morris"
    baseStr = "parser"
    print(s.smallestEquivalentString(s1, s2, baseStr))
