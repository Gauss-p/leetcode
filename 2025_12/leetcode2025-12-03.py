from typing import List
from collections import defaultdict

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        # 为了统计梯形的数目，我们需要先考虑四个点应满足什么条件才能构成一个梯形。根据梯形的定义，我们需要找到两条不重合的平行线，在每一条线上分别找两个点，那么这四个点就一定可以构成一个梯形。因此，我们可以循环所有可能的点对，将其对应的直线斜率和截距分类存入字典中，同时，为了查找方便，我们可以采用嵌套字典，在父字典中，每一个斜率对应一个字典，而在斜率对应的每一个子字典中，每一个截距对应一个数字，表示该斜率和截距对应的点对出现次数
        # 这样一来，我们就可以对每一个斜率k，根据对应的截距统计数据，分别计算「平行的一组边的斜率均为k」的梯形总数量，注意，在计算的时候，因为我们在统计时是按照两个点两个点累加数据的，因此通过父字典用斜率k和截距b索引出的数据就正好是对应直线上可能的边的总数量，不需要用组合数再求一次
        # 但是可以发现，单纯这样计算，如果遇到平行四边形，我们就会将它们计算两次，因此还需要统计出所有平行四边形的数量，用梯形总数量减去即可得到答案。为了确定平行四边形，需要用到平行四边形的判定：对角线互相平分的四边形是平行四边形，也就是说，我们只需要知道所有线段的中点坐标和斜率，并按照它们进行归类存入字典中，也是同样的结构，嵌套字典，外侧键值为中点坐标，内侧键值为直线斜率，这样，我们就可以计算「中点相同，斜率不同」的线段对总数，而每一对正好就是一个平行四边形
        # 计算平行四边形的个数的方法和计算梯形的类似，将加号改为减号即可
        kb_dict = defaultdict(lambda : defaultdict(int)) # 按照斜率和截距分类线段
        mk_dict = defaultdict(lambda : defaultdict(int)) # 按照中点和斜率分类线段
        for i in range(len(points)):
            x1, y1 = points[i]
            for j in range(i+1, len(points)):
                x2, y2 = points[j]
                # 注意这里在处理斜率的时候需要判断线段是否是垂直于x轴的直线，如果是，就需要将斜率置为无穷大，同时为了区分不同直线，我们可以将截距置为线段所在直线和x轴交点
                dx, dy = x2-x1, y2-y1
                midx, midy = x1+x2, y1+y2
                k, b = float("inf"), x1 # dx为0的情况
                if dx != 0:
                    # dx不为0的情况
                    k = dy/dx
                    b = (y1*dx-dy*x1)/dx

                kb_dict[k][b] += 1
                mk_dict[(midx, midy)][k] += 1
        
        res = 0
        for b in kb_dict.values():
            # 计算梯形总个数
            s = 0
            for ib in b.values():
                res += s*ib
                s += ib
        
        for k in mk_dict.values():
            # 减去平行四边形总个数
            s = 0
            for ik in k.values():
                res -= s*ik
                s += ik
        
        return res

if __name__ == "__main__":
    s = Solution()
    points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]
    print(s.countTrapezoids(points))
