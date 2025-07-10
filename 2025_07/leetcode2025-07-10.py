from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        # 主要思路如下：对于每一个会议，我们考虑两种移动情况：1.不超过两边的会议，也就是保持相对顺序不变，2.超过两边的会议，空出中间的一大段空闲时间
        # 对于第一种情况，我们只需用该会议的后一个会议的开始时间减去前一个会议的结束时间，就可以得到该会议在不超过两边会议的前提下能够移动的最大空间，然后将该会议移动到该空间的最左侧，此时空出来的空闲时间就是最大空间的大小减去当前会议的长度，即：startTime[i+1]-endTime[i-1]-(endTime[i]-startTime[i])
        # 对于第二种情况，我们需要在一个前提下才能实现：前一个会议的左边有一个空间可以将该会议放入，或是后一个会议的右边有一个空间可以将该会议放入，因此我们考虑前缀空间最大值和后缀空间最大值，对于每一个会议只需判断它前后的空间最大值是否大于等于当前会议的长度，如果是，就可以将中间空出来的空闲时间统计入答案
        n = len(startTime)
        events = list(zip(startTime, endTime))
        # 合并两个列表，并在会议列表前后加入两个哨兵，便于计算
        events.insert(0, (0,0))
        events.append((eventTime, eventTime))
        
        preMaxSpace = [0]*(n+2) # 定义preMaxSpace[i]表示第i个会议左边的最大空间长度
        for i in range(n+1):
            preMaxSpace[i+1] = max(preMaxSpace[i], events[i+1][0]-events[i][1])
        afterMaxSpace = [0]*(n+2) # 定义afterMaxSpace[i]表示第i个会议右边的最大空间长度
        for i in range(n, -1, -1):
            afterMaxSpace[i] = max(afterMaxSpace[i+1], events[i+1][0]-events[i][1])

        res = 0
        for i in range(1, n+1):
            curLength = events[i][1]-events[i][0]
            cur = events[i+1][0]-events[i-1][1]-(events[i][1]-events[i][0]) # 先是第一种情况，不超过两边的移动
            if preMaxSpace[i-1] >= curLength or afterMaxSpace[i+1] >= curLength:
                # 只有在前后的空间最大值大于等于当前会议的长度时，才能将该会议移动至超过两边的位置
                cur += curLength # 这里直接加上当前会议的长度还原中间的空间即可
            res = max(res, cur)
        return res

if __name__ == "__main__":
    s = Solution()
    eventTime = 10
    startTime = [0,7,9]
    endTime = [1,8,10]
    print(s.maxFreeTime(eventTime, startTime, endTime))
