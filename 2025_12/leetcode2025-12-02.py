from typing import List
from collections import defaultdict

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        # 将所有点按行分类，在每一行中选取两个数字，将所有情况相乘求和即可
        cnt = defaultdict(int)
        for x,y in points:
            cnt[y] += 1
        
        modNum = 1_000_000_007
        res = 0
        tot = 0
        for k,v in cnt.items():
            cur = (v-1)*v//2
            res = (res+tot*cur)%modNum
            tot = (tot+cur)%modNum
        return res

if __name__ == "__main__":
    s = Solution()
    points = [[1,0],[2,0],[3,0],[2,2],[3,2]]
    print(s.countTrapezoids(points))
