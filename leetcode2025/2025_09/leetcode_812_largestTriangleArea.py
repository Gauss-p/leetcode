from typing import List

class Solution:
    def largestTriangleArea(self, p: List[List[int]]) -> float:
        res = 0
        for i in range(len(p)):
            for j in range(i+1, len(p)):
                for k in range(j+1, len(p)):
                    # vector1 = [p[j][0]-p[i][0], p[j][1]-p[i][1]]
                    # vector2 = [p[k][0]-p[i][0], p[k][1]-p[i][1]]
                    # cur = abs(vector1[0]*vector2[1]-vector1[1]*vector2[0])/2
                    cur = abs((p[j][0]-p[i][0])*(p[k][1]-p[i][1])-(p[j][1]-p[i][1])*(p[k][0]-p[i][0]))/2
                    if cur > res:
                        res = cur
        return res

if __name__ == "__main__":
    s = Solution()
    p = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    print(s.largestTriangleArea(p))
