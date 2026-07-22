from typing import List
from bisect import *

class SparseTable:
    def __init__(self, groups):
        n = len(groups)
        m = n.bit_length()
        st = [[] for _ in range(m)]
        for i in range(n-1):
            l1, r1 = groups[i]
            l2, r2 = groups[i+1]
            st[0].append(r1-l1+r2-l2)
        
        for i in range(1, m):
            for j in range(n-(1<<i)):
                st[i].append(max(st[i-1][j], st[i-1][j+(1<<(i-1))]))
        self.st = st
    
    def query(self, l, r):
        if l>=r:
            return 0
        k = (r-l).bit_length()-1
        return max(self.st[k][l], self.st[k][r-(1<<k)])

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: List[List[int]]) -> List[int]:
        # 实际上本题要求的不过是每个查询区间[l,r]中，相邻两个连续0子字符串长度和的最大值。
        # 相邻两个连续0子字符串表示，在将s按照0和1分段后，去掉连续1的字串，在剩余的所有连续0字串中相邻的两个，举个例子，如果字符串是'01001000'，那么分段并去除连续1字串后，剩余子串只有[0,00,000]，这样，[0,00]和[00,000]就是两个相邻连续0子字符串了，而根据题目的规则，在这个字符串中可以把0变成1的选择正包含了这两个子字符串。
        
        # 由于要求一个区间内的某种东西的最大值，因此可以想到用稀疏表来实现。先将原字符串中的每个连续0子字符串都按照(左端点下标，右端点下标)的形式保存下来，之后通过稀疏表即可求出多个连续0子字符串中，相邻两个的长度和的最大值，但查询的下标并不能保证它们之间一定都是完整的连续0子字符串，因此需要根据不同的情况对查询区间最左侧和最右侧连续0子字符串进行单独处理，这样才能计算出所有可能的情况。

        # 需要注意的是，当计算相邻两个残缺区间能够组成的最大长度和时，如果某个区间不存在(即计算出的左端点大于右端点)，那么应当直接返回0，否则才返回两个区间长度之和。
        s += '2'
        n = len(s)
        cnt1 = 0
        groups = [(-1,-1)]
        last = 0
        for i in range(1, n):
            cnt1 += (s[i-1]=='1')
            if s[i]!=s[i-1]:
                if s[i-1]=='0':
                    groups.append((last, i))
                last = i
        groups.append((n, n)) # 分组，加哨兵

        def sumLength(a, b): # 计算两个残缺区间能够组成的长度和
            return a+b if a>0 and b>0 else 0

        st = SparseTable(groups)
        res = []
        for l,r in queries:
            r += 1
            il = bisect_left(groups, l, key = lambda x:x[0])
            ir = bisect_right(groups, r, key = lambda x:x[1])-1

            ans = 0
            if il<=ir:
                ans = max(st.query(il, ir), # 完整连续0子字符串中，相邻两个的最大长度和
                          sumLength(groups[il-1][1]-l, groups[il][1]-groups[il][0]), # 左侧残缺区间计算
                          sumLength(groups[ir][1]-groups[ir][0], r-groups[ir+1][0])) # 右侧残缺区间计算
            elif il == ir+1:
                ans = sumLength(groups[il-1][1]-l, r-groups[ir+1][0])
            
            res.append(ans+cnt1)
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "01"
    queries = [[0,1]]
    print(sl.maxActiveSectionsAfterTrade(s, queries))
