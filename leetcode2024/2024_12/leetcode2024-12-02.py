class Solution:
    def totalNQueens(self, n: int) -> list[list[str]]:
        # setQueens用递归的方式求出皇后的每一种排列方式
        def setQueens(rowIndex: int):
            if rowIndex == n:
                # 递归基，如果rowIndex已经为n，说明每一行的位置都已计算完，即为一种情况
                return 1
            cnt = 0
            for i in range(n):
                if (i in col) or (rowIndex-i in diagonal1) or (rowIndex+i in diagonal2):
                    # i用来循环当前行的皇后位置，如果i在之前已经出现，那么不能进行循环
                    # 接下来还需判断对角线，我们发现，从左上到右下的对角线上所有位置[i][j]，i-j都是定值，而从右上到坐下的对角线上所有位置[i][j]，i+j都是定值，所以如果rowIndex-i或rowIndex+i的值之前已经出现过，就说明当前位置和之前的某个位置在同一条对角线上，会攻击，因此跳过
                    continue
                col.add(i)
                diagonal1.add(rowIndex-i)
                diagonal2.add(rowIndex+i)
                # 以上操作是将当前位置加入已选择的位置之中
                cnt += setQueens(rowIndex+1)
                col.remove(i)
                diagonal1.remove(rowIndex-i)
                diagonal2.remove(rowIndex+i)
                # 恢复现场
            return cnt

        col = set()
        diagonal1 = set()
        diagonal2 = set()
        # 从第0行开始填
        return setQueens(0)

if __name__ == "__main__":
    s = Solution()
    n = 13
    print(s.totalNQueens(n))
