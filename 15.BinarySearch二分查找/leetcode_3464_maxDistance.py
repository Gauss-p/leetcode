from typing import List
from bisect import *

class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        # 可以发现，每两个点之间的曼哈顿距离都等于沿着正方形的边走的距离，因此为了处理方便，可以将正方形的边展开成一条直线，这样，每一个二维坐标就可以转化为一个一维坐标，更容易计算。将所有一维坐标按顺序存储在一个列表pos中。
        # 接下来，针对题目中的「最小...最大化」，即可使用二分查找解决。对于二分查找中的检查函数check，需要做的就是检查：在pos中查找是否存在k个位置，使得每两个相邻位置的距离都大于等于给出的限定距离mid.
        # 在check函数中可以先确定一个起始位置，然后根据mid寻找下一个值，总共寻找k-1次，不过需要注意的是，由于找到的所有位置会构成一个环，因此需要判断找到的下一个位置和起始位置的距离是否已经小于mid了，如果是，则不能继续找下去，需退出循环，否则还可以继续寻找。
        # 以上的所有计算都是在确定起始位置的基础上进行的，因此还需要循环所有可能的起始位置，只要有一个位置计算出来是可行的，即可直接返回True，而如果所有位置都不可行，则需返回False
        pos = []
        for x,y in points:
            if x == side or y == 0:
                pos.append(x+y)
            else:
                pos.append(4*side-(x+y))
        pos.sort()
        pos += [4*side+x for x in pos] # 使所有位置构成循环数组
        
        def check(mid):
            for indx in range(len(points)): # 遍历所有起始位置
                flag = True
                first = pos[indx]
                for i in range(k-1):
                    last = pos[indx]
                    indx = bisect_left(pos, pos[indx]+mid) # 二分内部
                    if 4*side-(pos[indx]-first) < mid:
                        flag = False
                        break
                if flag:
                    return True
            return False
        
        l, r = 0, side*4+1
        while l<=r:
            mid = (l+r)//2
            if check(mid):
                l = mid+1
            else:
                r = mid-1
        return r

if __name__ == "__main__":
    s = Solution()
    side = 2
    points = [[0,2],[2,0],[2,2],[0,0]]
    k = 4
    print(s.maxDistance(side, points, k))
