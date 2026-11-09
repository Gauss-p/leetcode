from heapq import *

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        # 如果想要通过小顶堆顺利求出当前空闲的服务器中位于位置i右侧的最近服务器，那么就需要将所有服务器的编号映射到区间[i,i+k)内，同时保证变换后的结果与原来的编号对模k同余。举个例子，如果当前正在处理索引为2的请求，同时总共有4个服务器，那么如果按照原先的索引，从2开始的环形数组就是[2,3,0,1]，但为了在小顶堆中直接得出结果，则需要将其变成[2,3,4,5]，可以发现，如果现在要对第i个请求将原先索引为j的服务器更新其下标后加入小顶堆，则可得到新的索引为：
        #   1.当j小于i时，就是j+k;
        #   2.当j大于等于i时，就保持j不变。
        # 可以用一个统一的公式表示，即：i+(i-j)%k。注意需要让(i-j)%k是正数。
        # 最后滚动统计即可
        if len(arrival) <= k:
            return list(range(len(arrival)))

        free = list(range(k))
        busy = []
        cnt = [0]*k
        maxCnt = 0
        res = []
        for i,(t,l) in enumerate(zip(arrival, load)):
            while len(busy) and busy[0][0] <= t:
                _, indx = heappop(busy)
                heappush(free, i+(indx-i)%k)
            
            if len(free) == 0:
                continue
            
            j = heappop(free)%k
            heappush(busy, (t+l, j))
            cnt[j] += 1

            if cnt[j] > maxCnt:
                maxCnt = cnt[j]
                res = [j]
            elif cnt[j] == maxCnt:
                res.append(j)
        
        return res

if __name__ == "__main__":
    s = Solution()
    k = 3
    arrival = [1,2,3,4,5]
    load = [5,2,3,3,3]
    print(s.busiestServers(k, arrival, load))
