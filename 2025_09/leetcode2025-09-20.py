from typing import List
from collections import defaultdict
from bisect import *

class Router:
    # 整体思路如下：由于题目中最主要的问题是查询目标地址为指定的destination的所有数据包中，时间戳位于[startTime, endTime]中的数量，同时，根据题目的最后一句话：对于 addPacket 的查询会按照 timestamp 的递增顺序进行。可以知道，在所有的操作中，给出的数据都可以保证所有的时间戳是按照加入列表的时间非单减的，因此我们只需要将所有的时间戳按照目标地址归类，就可以使用二分查找来查找单个目标地址对应的所有数据包中时间戳在[startTime, endTime]中的数量了
    # 因此，我们需要一个单独的字典dest_packet来存储每一个目标地址对应的所有时间戳，并按照加入的顺序排列
    # 同时，为了实现forwardPacket要求的“按照先进先出”的顺序转发下一个数据包，我们需要用一个列表allPacket，用来存储每一个数据包的三个数据，这样，每次弹出allPacket中第0个元素，就可以实现“先进先出”的顺序了
    # 但对于第一个函数addPacket，我们需要保证新给出的数据包没有出现过，因此需要一个字典isPacketIn来存储每一个数据包(s,d,t)是否出现过，如果出现过，对应值就是1，这样我们只需在最开始判断即可跳过所有出现过的数据包。而对于没有出现过的数据包，则需要将其先分别加入地址字典dest_packet中，并将其在isPacketIn中标记出现，同时将其加入allPacket中即可。但是题目又要求总共数据包数量不能超过memoryLimit，因此当allPacket中的元素总数超过memoryLimit时，就调用forwardPacket函数将第一个元素删除即可
    def __init__(self, memoryLimit: int):
        self.memoLim = memoryLimit
        self.allPacket = []
        self.dest_packet = defaultdict(list)
        self.isPacketIn = defaultdict(int)

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        curPacket = (source, destination, timestamp)
        if self.isPacketIn[curPacket] == 1: # 出现过，无法加入
            return False
        self.allPacket.append(curPacket)
        self.dest_packet[destination].append(timestamp)
        self.isPacketIn[curPacket] = 1
        if len(self.allPacket) > self.memoLim: # 超出记忆最大数量
            self.forwardPacket()
        return True

    def forwardPacket(self) -> List[int]:
        if len(self.allPacket) == 0:
            return []
        curSource, curDest, curTimestamp = self.allPacket.pop(0) # 弹出第一个元素，遵循FIFO原则
        self.dest_packet[curDest].pop(0)
        self.isPacketIn[(curSource, curDest, curTimestamp)] = 0
        return [curSource, curDest, curTimestamp]

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        l = bisect_left(self.dest_packet[destination], startTime) # 二分查找，找出[startTime, endTime]中的时间戳总个数
        r = bisect_right(self.dest_packet[destination], endTime)-1
        return r-l+1

if __name__ == "__main__":
    memoryLimit = 3
    r = Router(memoryLimit)
    op = ["addPacket","addPacket","addPacket","addPacket","addPacket","forwardPacket","addPacket","getCount"]
    num = [[1,4,90],[2,5,90],[1,4,90],[3,5,95],[4,5,105],[],[5,2,110],[5,100,110]]
    for i in range(len(op)):
        if op[i] == "addPacket":
            print(r.addPacket(num[i][0], num[i][1], num[i][2]))
        if op[i] == "forwardPacket":
            print(r.forwardPacket())
        else:
            print(r.getCount(num[i][0], num[i][1], num[i][2]))
