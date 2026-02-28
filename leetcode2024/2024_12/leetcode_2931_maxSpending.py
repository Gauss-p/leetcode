from typing import List

class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        totVal = []
        for i in values:
            totVal.extend(i)
        totVal.sort()
        res = 0
        for i,v in enumerate(totVal):
            res += (i+1)*v
        return res
        # res,day = 0,1
        # n,m = len(values[0]),len(values)
        # indx = [-1]*m
        # for i in range(n*m):
        #     tmpIndx,v = 0,inf
        #     for j in range(0,m):
        #         if indx[j] != -n-1 and values[j][indx[j]] < v:
        #             v = values[j][indx[j]]
        #             tmpIndx = j
        #     res += values[tmpIndx][indx[tmpIndx]]*day
        #     day += 1
        #     indx[tmpIndx] -= 1
        # return res

if __name__ == "__main__":
    s = Solution()
    values = [[8,5,2],[6,4,1],[9,7,3]];
    print(s.maxSpending(values))
