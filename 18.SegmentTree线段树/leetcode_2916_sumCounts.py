from typing import List
from collections import defaultdict

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        # 本题实际上可以这样想：定义一个数组diff，它会随着nums中元素的循环不断更新，假设当前循环到nums[j]，那么diff[i]则表示nums[i:j]中的不同元素数目。

        # 题目要求的是所有子数组中不同元素数目的平方和，那么将其拆分成两个问题：
        #   1.求出以每个位置为结尾的所有子数组的不同元素数目总和；
        #   2.维护每个子数组不同元素数目的平方之和；

        # 第一个问题比较简单，根据nums[i]是否出现过可以分两种情况：
        #   1.nums[i]在之前从来没有出现过，那么此时diff数组中位于区间[0,i]的全部位置都会加1，因为都多出了一个新元素；
        #   2.nums[i]在之前出现过，且上一次出现位置为last，那么此时diff数组中位于区间[diff+1,i]的全部位置都加1，前面的并不会因为nums[i]的出现而多一个新元素，只有后面的会。
        #   综上即得，当新统计一个位置nums[i]时，只有区间[last+1, i]中的所有位置x对应的diff[x]才会加1(其中当nums[i]是新元素时last=-1)。

        # 对于第二个问题，可以依赖上面的结果解决。遇到nums[i]时，diff数组中的元素值会如何变化？根据上面的分析，对于任意的x∈[last+1, i](其中当nums[i]是新元素时last=-1)，都需要将diff[x]+1。接下来考虑变化的那部分区间内平方之和的变化，由于这个区间内每一个元素都加了1，因此实际上对于原先值是v的位置需要累加的变为(v+1)**2，即v**2+2*v*1+1**2，将其拆分可发现v**2可以直接通过原平方和得到，2*v*1可以通过2*1*sum得到，其中sum为区间中所有元素之和，而1**2在累加之后直接用区间长度length乘以1**2即可得到。也就是说，可以通过维护区间的总和及平方和来递推出新的平方和。

        # 综上，可以发现无论是维护总和还是平方和，都需要对diff数组的某个特定区间进行维护，也就意味着本题需要用区间进行不断操作，那么可以想到用线段树的算法，总共用三个数组，sum1,sum2,lazy，其中sum1用来统计树中某个特定节点对应的diff区间中的元素总和；sum2用来统计区间中的元素平方总和；lazy是懒标记，用来记录树中某个节点对应的区间是否存在需要增加但还未增加的数量，当不强制要求操作时，直接记录即可，否则，当需要计算答案时才将lazy中存储的数量一次性进行更新。

        n = len(nums)
        modNum = 1_000_000_007
        sum1 = [0]*(4*n)
        sum2 = [0]*(4*n)
        lazy = [0]*(4*n)

        def add(indx, l, r, k):
            # 因为懒标记的存在，不一定每次都只增加1，因此需要用k代替上面公式中的1
            length = r-l+1
            sum2[indx] = (sum2[indx]+2*k*sum1[indx]+length*k*k)%modNum
            sum1[indx] = (sum1[indx]+length*k)%modNum
        
        def down(indx, l, r):
            # 用来更新懒标记
            nxt = indx<<1
            mid = (l+r)//2

            lazy[nxt] += lazy[indx] # 传到左子节点
            add(nxt, l, mid, lazy[indx])

            lazy[nxt|1] += lazy[indx] # 传到右子节点
            add(nxt|1, mid+1, r, lazy[indx])

            lazy[indx] = 0 # 已经更新完毕
        
        def modify(indx, l, r, ql, qr):
            # 将diff数组中[ql,qr]中的元素都加1
            if ql <= l and r <= qr:
                add(indx, l, r, 1)
                lazy[indx] += 1
                return
            
            if lazy[indx]: # 需要算了，不得不操作了
                down(indx, l, r)
            
            nxt = indx<<1
            mid = (l+r)//2
            if ql <= mid:
                modify(nxt, l, mid, ql, qr)
            if qr > mid:
                modify(nxt|1, mid+1, r, ql, qr)

            sum1[indx] = (sum1[nxt]+sum1[nxt|1])%modNum
            sum2[indx] = (sum2[nxt]+sum2[nxt|1])%modNum
        
        res = 0
        last = defaultdict(int)
        for i in range(1, n+1):
            lastPos = last[nums[i-1]]
            modify(1, 1, n, lastPos+1, i) # 从1开始编号diff，可以防止defaultdict默认值0与下标重复
            last[nums[i-1]] = i
            res = (res+sum2[1])%modNum
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,1]
    print(s.sumCounts(nums))
