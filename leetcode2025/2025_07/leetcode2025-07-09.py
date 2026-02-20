from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        # 滑动窗口，每一次都只移动连续k个会议，贪心地想，对于每k个会议，肯定是将它们首尾相接排到最左边或最右边才能达到最大的空闲时间段，因此，我们记录k个会议的时间总长度，然后在当前所在的空间中排到最左边即可。那么当前所在空间如何确定呢？该空间的右端点应当设置为这k个会议后边一个会议的左端点，而该空间的左端点应当设置为这k个会议前面一个会议的右端点，因此，如果当前k个会议的最右边一个索引为i，那么这k个会议可以自由移动的空间就应该是[endTime[i-k], startTime[i+1]]
        # 接下来，我们可以统计出这k个会议的总长度，假设为cur，那么将它们全部排到左边能够产生的最长空闲时间就是：startTime[i+1]-endTime[i-k]-cur
        # 然后用滑动窗口的方式维护cur的值即可
        # 在代码实现中，我们可以将startTime和endTime合成一个列表，来表示索引为i的会议的开始和结束时间
        # 注意，为了处理边界，我们在[0,eventTime]的左右边界分别加上两个哨兵，分别是[0,0]和[eventTime,eventTime]，这样可以方便我们计算处于边界的k个会议的移动空间
        n = len(startTime)
        events = list(zip(startTime, endTime))
        events.insert(0, [0,0])
        events.append([eventTime, eventTime])
        cur = 0 # 当前k个会议的长度总和
        res = 0
        for i in range(1, n+1):
            cur += events[i][1]-events[i][0]
            if i-1<k-1: # 这里i-1是因为i是从1开始编号的
                continue
            res = max(res, events[i+1][0]-events[i-k][1]-cur) # 记录当前能够达到的空闲时间总长
            cur -= events[i-k+1][1]-events[i-k+1][0] # 更新k个会议的长度总和
        return res

if __name__ == "__main__":
    s = Solution()
    eventTime = 5
    k = 1
    startTime = [1,3]
    endTime = [2,5]
    print(s.maxFreeTime(eventTime, k, startTime, endTime))
