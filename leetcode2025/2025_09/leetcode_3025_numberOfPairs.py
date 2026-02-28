from typing import List

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        # 对于每一个点，我们都以它为矩形左上角来计算合法矩形个数。也就是说我们需要找到所有合法的矩形右下角，那么可以发现，假如左上角坐标为(x1,y1)，右下角坐标为(x2,y2)，那么我们首先要保证x2>x1, y2<=y1，同时，如果在横坐标位于区间[x1,x2]中的点的纵坐标有位于区间[y2, y1]中的，那么这个矩形一定不合法
        # 因此我们可以这样想，首先将所有点按照横坐标升序和纵坐标降序排序，然后从头到尾循环每一个点，以这个点为左上角，再从下一个点开始循环到尾，作为备选右下角，这样，我们就可以保证右下角始终在左上角的右侧。接下来，为了保证右下角的纵坐标是前后两个点中间的纵坐标最大值，我们还需要维护一个纵坐标最大值maxY，每循环一个右下角就更新一次maxY，当且仅当y2<=y1且y2>maxY时，我们才记录一个答案
        points.sort(key = lambda x:(x[0], -x[1]))
        res = 0
        n = len(points)
        for i in range(n):
            x1, y1 = points[i]
            maxY = -float("inf")
            for j in range(i+1, n):
                x2, y2 = points[j]
                if y2<=y1 and y2>maxY: # 矩形中没有点
                    maxY = y2
                    res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    points = [[1,1],[2,2],[3,3]]
    print(s.numberOfPairs(points))
