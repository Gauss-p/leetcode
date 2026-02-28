from typing import List

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        # 注意到对角线上的所有位置的两个索引之和都是定值
        # op用来控制遍历顺序的正反，-1即为逆向，+1即为顺向
        myMin = lambda x,y : x if x<y else y
        myMax = lambda x,y : x if x>y else y
        m, n = len(mat), len(mat[0])
        op = -1
        res = []
        for curSum in range((m+n-2)+1):
            # curSum-i<=n-1 --> i>=curSum-n+1
            # curSum-i>=0 --> i<=curSum
            # curSum-n+1 <= i <= curSum
            low = myMax(curSum-n+1, 0)
            high = myMin(curSum, m-1)
            if op == -1:
                low, high = -high, -low
            for i in range(low, high+1):
                j = curSum-(abs(i))
                res.append(mat[abs(i)][j])
            op *= -1
        return res

if __name__ == "__main__":
    s = Solution()
    mat = [[1,2,3],[4,5,6],[7,8,9]]
    print(s.findDiagonalOrder(mat))
