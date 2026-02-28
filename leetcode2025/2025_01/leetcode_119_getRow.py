from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # 利用组合数的计算方法，C(n,m) = C(n,m-1)*(n-m+1)/m，可以只根据一行中的前一个数计算出当前数
        # 即：res[i] = res[i-1]*(rowIndex-i+1)//i
        res = [1]*(rowIndex+1)
        for i in range(1, rowIndex+1):
            res[i] = res[i-1]*(rowIndex-i+1)//i
        return res
        # -------------------------------------------------------------
        # if rowIndex==0:return [1]
        # if rowIndex==1:return [1,1]
        # res = [1,1]
        # for i in range(rowIndex-1):
        #     res = [1]+[res[j-1]+res[j] for j in range(1,i+2)]+[1]
        # return res
        # -------------------------------------------------------------
        # def dfs(x):0
        #     if x == 0:
        #         return [1]
        #     if x == 1:
        #         return [1,1]
        #     tmp = dfs(x-1)
        #     res = [1]+[tmp[i-1]+tmp[i] for i in range(1,len(tmp))]+[1]
        #     return res
        # return dfs(rowIndex)

if __name__ == "__main__":
    s = Solution()
    rowIndex = 10
    print(s.getRow(rowIndex))
