from typing import List
from functools import cache

class Node:
    def __init__(self):
        self.son = [None]*26
        self.sId = -1

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        # 首先，和这道题目的版本1一样，我们可以先求出original中各个子串转换成changed中可能的各个子串所需要的最小成本，这有两种方式，一种是用Dijkstra算法，根据初始条件建图，然后求出起点到图中各个点的最短路径即可得到，另一种是Floyd算法：根据初始条件，我们可以知道位置对应的字符串组进行转换的成本，之后，为了求出处在不同位置的字符串组进行转换的成本，可以遍历其余所有可能的字符串插在二者中间，计算可能的最小成本，即，在所有字符串的列表strs中，如果我们要计算strs[i]转换成strs[j]的最小成本，可以用k从头到尾遍历strs，计算先将strs[i]转换成strs[k]，再转换成strs[j]的成本之和，即为strs[i]到strs[j]的成本。定义dist[x][y]表示strs[x]转换成strs[y]的代价，那么当我们以k为中介时，就有：
        #               dist[i][j] = dist[i][k]+dist[k][j]
        # 因此，对所有可能的k进行循环，计算dist[i][k]+dist[k][j]的最小值即可
        # 但就算我们有了各个字符串之间相互转换的最小代价，仍然不能直接去找source和target中不同的位置然后直接替换，因为如果我们要将一个长度为5的子字符串转换，无法确定是直接转换代价更小还是将它分成两个更小的子字符串转换代价更小，因此我们需要暴力遍历所有情况，这里就需要用到dfs函数了
        # 定义dfs(indx)用来计算将source[indx:]变成和target[indx:]相同的最小代价，那么有两种情况：
        #       1.当source[indx]!=target[indx]时，说明indx位置一定要被改变，因此我们可以分别从source和target中的indx位置开始向后遍历同样的长度length，如果source[indx:indx+length]是strs中的一个完整单词，并且target[indx:indx+length]也是strs中的一个完整单词，那么我们就可以寻找两者在strs中的索引，即可在dist中查找到将前者变为后者的最小代价，之后用它再加上dfs(indx+length)即可得到dfs(indx)的值。如果用j表示indx+length，那么j的范围就是[indx, n-1]，并且dfs(indx) = dist[source[indx:j]][target[indx:j]]+dfs(j+1)，注意dist的索引实际上为在strs中的索引
        #       2.当source[indx]==target[indx]时，我们仍然可以选择将这个位置进行改变，因为就算进行了改变仍可能有某个位置无变化，这时的算法就和上面如出一辙，但此时我们可以选择不改变这个位置，此时就有dfs(indx)=dfs(indx+1)了
        
        # 综上所述，可以发现我们不仅需要有一个数据结构用来快速匹配字符串，同时还需要让它能够给出字符串在strs中的索引。因此可以想到「字典树」。用一个26叉树存储所有字符串，且各个字符串按照从左到右的顺序将所有字母在树中从上到下排列，这样，在从indx开始，在source和target中分别向后循环时，就可以不断匹配寻找strs中相同的字符串了，并且，为了在查询时方便找到一个字符串的结尾和它在strs中的索引，我们可以将树中每个节点加上一个属性:sId，当且仅当一个节点是某个字符串的结尾位置时才将sId设置为该字符串在strs中的索引。这样即可方便dfs函数中的查询了
        # 最后，返回的答案即为dfs(0)

        root = Node()
        curSId = 0
        
        def plugIn(s): # 建立26叉树(即字典树)
            tmp = root
            for i in s:
                indx = ord(i)-ord('a')
                if tmp.son[indx] == None:
                    tmp.son[indx] = Node() # 从上到下创建节点保存字符串
                tmp = tmp.son[indx]
            
            if tmp.sId == -1: # 如果在字符串结尾的位置并没有保存过其他strs中的索引，就将当前字符串在strs中的索引保存进去，同时将下一个待加入的索引右移一位
                nonlocal curSId
                tmp.sId = curSId
                curSId += 1
            return tmp.sId # 这里每插入一次我们都返回当前字符串对应的索引，即可方便dist的存储

        m = len(original)
        dist = [[float("inf")]*(2*m) for _ in range(2*m)] # 定义dist[x][y]表示strs[x]转换成strs[y]的代价
        for i in range(m):
            x, y, c = original[i], changed[i], cost[i] # 根据已有信息初始化dist
            xId = plugIn(x) # 根据插入函数返回的索引计算dist
            yId = plugIn(y)
            dist[xId][yId] = min(dist[xId][yId], c)

        for k in range(curSId): # 用floyd算法计算两两字符串之间转换的代价
            for i in range(curSId):
                if dist[i][k] == float("inf"):
                    continue
                for j in range(curSId):
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

        n = len(source)
        @cache
        def dfs(indx):
            if indx == n:
                return 0
            res = float("inf")
            if source[indx] == target[indx]: # 当前位置可以不进行变换
                res = min(res, dfs(indx+1))
            
            p, q = root, root
            for j in range(indx, n):
                i1 = ord(source[j])-ord('a')
                i2 = ord(target[j])-ord('a')
                p = p.son[i1] # 在树中分别向下查找两个字符串
                q = q.son[i2]
                if p is None or q is None: # 已经查不到任何匹配字符串了
                    break
                if p.sId == -1 or q.sId == -1: # 当前并非哪个字符串的末尾，无法直接交换
                    continue
                res = min(res, dist[p.sId][q.sId]+dfs(j+1))
            return res
        
        ans = dfs(0)
        return -1 if ans == float("inf") else ans

if __name__ == "__main__":
    s = Solution()
    source = "abcd"
    target = "acbe"
    original = ["a","b","c","c","e","d"]
    changed = ["b","c","b","e","b","e"]
    cost = [2,5,5,1,2,20]
    print(s.minimumCost(source, target, original, changed, cost))
