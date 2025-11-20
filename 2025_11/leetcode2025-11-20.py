from typing import List

class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        # 首先，为了满足所有区间中都至少有两个数字在最终的数组里，我们肯定最先对那些长度最小的区间进行选择是最优的，因为这样我们就可以通过选择长度较小区间中的两个数来尽可能满足更多的大数组的需求。同时，如果我们是按照区间的位置从后向前遍历的，那么为了让在当前区间中选择的两个数字拥有最大的和前一个区间重叠的可能，我们就需要选择当前区间最小的数字和最小数字加1作为当前选择的两个数字
        # 因此，我们需要将所有区间按照起点从小到大，终点从大到小的方式排列
        # 贪心地想，通过模拟的方式，按照区间的位置从后向前遍历，每一次都维护当前nums中最小的两个数字，然后和当前区间进行判断，如果两个数字都在该区间中，那么就表明我们不需要新增任何数字，直接跳过即可；如果两个数字均不在该区间中，那么就表明我们需要新增两个数字，同时需要更新最小的两个数字为新增的两个；如果该区间包含了最小两个数字中较小的那一个，但没有包含较大的那一个，我们就需要在该区间中新选择一个数字，同时将nums最小数更新为新选择数字，且将次小数更新为原先最小数
        # 综上所述，假设当前已统计的nums中最小两个数字分别为cur和nxt，且当前区间为[l,r]，那么:
        #   1.若r>=nxt，且因为在排序时已经保证左端点是递增的，因此可以保证l<=cur<nxt<=r，此时不需要新增任何数字
        #   2.若r<cur，则表明需要新增两个数字，因此答案累加2，同时cur更新为l，nxt更新为l+1
        #   3.若cur<=r<nxt，则表明需要新增一个数字，因此答案累加1，同时nxt更新为cur，cur更新为l
        intervals.sort(key = lambda x:(x[0], -x[1]))
        res = 2
        cur, nxt = intervals[-1][0], intervals[-1][0]+1
        for l, r in reversed(intervals[:-1]): # 倒序遍历
            if r >= nxt: # 最小两数均包含在[l,r]中
                continue
            if r < cur: # 最小两数均不包含在[l,r]中
                cur = l
                nxt = l+1
                res += 2
            else: # 最小两数有一个包含在[l,r]中
                nxt = cur
                cur = l
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    intervals = [[1,3],[3,7],[8,9]]
    print(s.intersectionSizeTwo(intervals))
