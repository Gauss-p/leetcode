from typing import List

class UFS:
    def __init__(self, n):
        self.pa = list(range(n))
    
    def find(self, x):
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        self.pa[px] = py
    
    def isSame(self, x, y):
        # 判断x和y是否在同一个连通块中
        return self.find(x)==self.find(y)

class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        # 可以发现，如果有多个人在同一时刻都开会，且这些人可以通过一些会议连成一个连通块，那么只要其中有一个人知道秘密，所有人都会知道秘密，因此，对于发生在同一时间的所有会议，我们都可以用一个并查集来将它们连成不同的连通块，然后判断是否有人知道秘密。但如果对于每一个时间都重新开一个并查集，太过麻烦，因此可以用一个并查集来模拟：如果我们始终维护并查集中的所有人都是已经知道秘密的，那么它们一定仅仅构成一个连通块，这时，将同一时间发生的所有会议都加入并查集之中，那么一定会有一个连通块是和0连起来的，即原先的一个连通块加上当前新增的部分相互连通的编号，这时，对于那些不在这个连通块内的所有编号，它们都一定无法知道秘密，因此就将它们全部相互分离成单个编号的连通块，只留下一个最大的那个即可
        # 为了判断一个编号是否需要被重置为大小为1的连通块，我们需要判断它是否和0在同一个连通块内，这时就需要判断两者的祖先是否相同，即find(x)和find(0)是否相同，如果相同则说明它们在同一个连通块内，此时将pa[x]重置为x，即表明将它分离即可。
        # 最后，循环所有人，判断他和0是否在同一个连通块内，如果在，那么一定可以知道秘密，此时将他的编号加入答案数组即可
        meetings.sort(key = lambda x:x[2]) # 按照时间顺序排序
        ufs = UFS(n)
        ufs.union(0, firstPerson) # 0时刻，firstPerson知道秘密
        
        m = len(meetings)
        i = 0
        while i<m:
            start = i
            time = meetings[i][2]
            while i<m and meetings[i][2]==time:
                ufs.union(meetings[i][0], meetings[i][1]) # 全部加入
                i += 1
            
            for j in range(start, i):
                x, y, _ = meetings[j]
                if not ufs.isSame(x, 0): # x不可能知道秘密
                    ufs.pa[x] = x
                if not ufs.isSame(y, 0): # y不可能知道秘密
                    ufs.pa[y] = y
        
        res = []
        for i in range(n):
            if ufs.isSame(i, 0): # i知道秘密
                res.append(i)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 6
    meetings = [[1,2,5],[2,3,8],[1,5,10]]
    firstPerson = 1
    print(s.findAllPeople(n, meetings, firstPerson))
