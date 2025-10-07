from typing import List
from collections import defaultdict
from bisect import *

class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        # 直接从头到尾循环，时刻维护一个晴天列表和每一个湖泊的上一次下雨日期，这样，只要再次碰到一个湖泊下雨，我们就可以直接调出它上一次下雨日期，并且直接再在晴天列表中查询第一个在该日期之后的晴天，然后将这个晴天日期所对应的答案置为这个湖泊的编号即可。注意，因为我们是从头到尾循环的，因此无论如何，晴天列表中的所有元素都始终保持有序，那么我们在查询第一个在上次下雨日期之后的晴天时就可以采用二分查找的方式
        # 如果在一个湖泊第二次下雨的时候，出现晴天列表为空或其中的最大日期还小于该湖泊上次下雨的日期，就说明这个湖泊一定会发生洪水，无法避开，直接返回空列表即可
        # 注意，如果出现形似[1,2,0,0,0,1,2]的示例，也就是在将所有湖泊都抽干的情况下还有晴天，那么直接将其全部填充成1即可
        n = len(rains)
        res = [-1]*n
        def init():
            return -1
        rainDays = defaultdict(init)
        sunny = []
        for i in range(len(rains)):
            if rains[i] == 0:
                sunny.append(i)
            else:
                if rainDays[rains[i]] != -1:
                    last = rainDays[rains[i]]
                    if len(sunny)==0 or sunny[-1] < last:
                        return []
                    indx = bisect_left(sunny, last)
                    day = sunny[indx]
                    sunny.pop(indx)
                    res[day] = rains[i]
                rainDays[rains[i]] = i
        while len(sunny):
            res[sunny.pop()] = 1
        return res

if __name__ == "__main__":
    s = Solution()
    rains = [1,2,0,0,2,1]
    print(s.avoidFlood(rains))
