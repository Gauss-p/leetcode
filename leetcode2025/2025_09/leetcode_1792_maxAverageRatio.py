from typing import List
from heapq import *

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        # 想让平均通过率增加得更多，由于班级数量不变，就需要让单个班级通过增加一个聪明学生而增加的通过率最大。而对于一个班级，假如原先有a个学生可以通过，总共有b个学生，那么原先通过率就是a/b，增加一个聪明学生，则a+1，b+1，因此增加后的通过率就是(a+1)/(b+1)，因此两者相减即可得到一个班级增加一个聪明学生后可以增加的通过率大小
        # 贪心地想，我们将每一个班对应的可增加通过率数量存入一个大顶堆，每次弹出最大的，并根据对应的索引对classes中的值进行更改同时重新加入堆中。每进行一次这样的操作就将extraStudents减1，一直到它变成0为止
        # 最后，对于classes中最终数据重新计算平均通过率即可
        q = []
        for i, (a,b) in enumerate(classes):
            heappush(q, (-((a+1)/(b+1)-a/b), i)) # 可增加通过率数量以及对应索引

        while extraStudents > 0:
            _, indx = heappop(q) # 更改索引对应的班级信息
            classes[indx][0] += 1
            classes[indx][1] += 1
            a, b = classes[indx]
            heappush(q, (-((a+1)/(b+1)-a/b), indx)) # 将新的值重新加入堆
            extraStudents -= 1

        res = 0
        for a,b in classes:
            res += (a/b)
        return res/len(classes)

if __name__ == "__main__":
    s = Solution()
    classes = [[1,2],[3,5],[2,2]]
    extraStudents = 2
    print(s.maxAverageRatio(classes, extraStudents))
