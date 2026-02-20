from typing import List
from bisect import *
from collections import defaultdict

class Solution:
    def maximumBeauty(self, Items: List[List[int]], queries: List[int]) -> List[int]:
        # 我们可以直接求出每一个价格对应的最大美丽值，之后进行二分查找即可
        cnt = defaultdict(int)
        for item in Items:
            p,b = item
            cnt[p] = max(cnt[p], b)
        tot = list(map(list, cnt.items()))
        tot.sort()
        # 为了之后不用再从头开始计算所有小于查询价格的最大美丽值，可以直接预处理，将每一个价格对应的美丽值都置为小于它的所有价格的美丽值的最大值
        for i in range(1,len(tot)):
            tot[i][1] = max(tot[i][1], tot[i-1][1])

        n = len(queries)
        res = [0]*n
        for i,q in enumerate(queries):
            # 直接二分查找即可
            indx = bisect_left(tot, [q, float("inf")])
            # 对于小于items中所有价格的查询，答案为0
            if indx != 0:
                res[i] = tot[indx-1][1]
        return res

if __name__ == "__main__":
    s = Solution()
    items = [[1,2],[3,2],[2,4],[5,6],[3,5]]
    queries = [1,2,3,4,5,6]
    print(s.maximumBeauty(items, queries))
