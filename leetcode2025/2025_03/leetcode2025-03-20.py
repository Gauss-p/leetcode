from typing import List
from collections import defaultdict,deque
from bisect import *

class Solution:
    def minReverseOperations(self, n: int, p: int, banned: List[int], k: int) -> List[int]:
        # ban = defaultdict(int)
        # for i in banned:
        #     ban[i] = 1
        # ban[p] = 1

        # res = [-1]*n
        # res[p] = 0
        # q = deque([p])
        # while q:
        #     i = q.popleft()
        #     mn = max(i-k+1, k-i-1)
        #     mx = min(i+k-1, 2*n-k-i-1)
        #     for j in range(mn, mx+1, 2):
        #         if ban[j] != 1:
        #             res[j] = res[i]+1
        #             q.append(j)
        #             ban[j] = 1
        # return res
        # -----------------------------------------
        # 首先举一个例子，对于一个长度n=7的数组，k=4，首先不考虑banned对翻转位置的限定。如果1在索引为3的位置，那么经过长度为4的子数组的翻转，它可以到达:0,2,4,6，在这个情况下，我们不需要考虑长度为k的子数组的边界超限的问题，那么，如果1在索引为2的位置怎么办呢？通过模拟，我们可以发现，它可以到达:1,3,5，而如果强行将长度为4的子数组的最右边放到索引2的地方，它将会被翻转到-1的位置
        # 通过观察，我们可以得出，一个位置i最左能翻转到的位置就是以下两个位置的最大值：1.以0为开始的长度为k的子数组将i翻转到的位置 2.以i为结尾长度为k的子数组将i翻转到的位置。第一种情况在i<k-1的时候适用，第二种情况在i>=k-1的时候适用。写成代数式就是：mn=max(i-k+1, k-i-1)，其中mn就是i能够翻转到的最左边的位置
        # 同理我们可以得出，一个位置i最右能翻转到的位置就是以下两个位置的最小值：1.以n-1为结尾的长度为k的子数组将i翻转到的位置 2.以i为开始长度为k的子数组将i翻转到的位置。第一种情况在i>n-k的时候适用，第二种情况在i<=n-k的时候适用。写成代数式就是：mx=min(n-k+(n-i-1), i+k-1)=min(2*n-k-i-1, i+k-1)
        # 并且，根据第一段的分析，我们可以发现每一个位置可以翻转到的位置的索引的奇偶性都一样，所以我们直接将所有能够被跳转到的奇数位置和偶数位置分别存放，之后直接先查找到mn的位置，直接往后循环到mx即可
        # 整体我们用BFS的思路，从位置p出发，不断往外标记可以跳转到的位置所需的步数即可。为了防止重复计算，我们在每一次标记的同时删除奇偶位置存储列表中的相应值即可
        banned = set(banned)
        res = [-1]*n
        res[p] = 0
        pos_even_odd = [[],[]] # 存储可以被跳转到的奇偶位置
        for i in range(n):
            if i not in banned and i != p:
                pos_even_odd[i%2].append(i)
        # 加入右端哨兵，防止二分查找超限
        pos_even_odd[0].append(n)
        pos_even_odd[1].append(n)
        
        q = deque([p])
        while q:
            i = q.popleft()
            # 计算位置i可以翻转到的最左端和最右端
            mn = max(i-k+1, k-i-1)
            mx = min(i+k-1, 2*n-k-i-1)
            curPos = pos_even_odd[mn%2] # 取出当前所需的奇偶位置列表
            indx = bisect_left(curPos, mn)
            while curPos[indx]<=mx:
                # 每一次标记跳转次数的同时删除位置，防止重复计算
                # 其中indx不需要加1是因为每次删除后，之后的元素都会左移
                j = curPos.pop(indx)
                res[j] = res[i]+1
                q.append(j)
        return res

if __name__ == "__main__":
    s = Solution()
    n, p = 4, 0
    banned = [1,2]
    k = 4
    print(s.minReverseOperations(n,p,banned,k))
