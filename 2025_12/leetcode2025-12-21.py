from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        # 贪心，维护已经选择的每一行字母，对于循环到的每一列，分别尝试添加在每一行之后，如果出现添加后不符合字典序的情况，就说明当前列不能被添加，否则就直接将该列添加在最后一列即可
        m, n = len(strs), len(strs[0])
        res = 0
        tot = ['']*m
        for j in range(n):
            flag = True
            for i in range(m-1):
                if tot[i]+strs[i][j] > tot[i+1]+strs[i+1][j]:
                    res += 1
                    flag = False
                    break
            if flag:
                for i in range(m):
                    tot[i] += strs[i][j]
        return res

if __name__ == "__main__":
    s = Solution()
    strs = ["ca","bb","ac"]
    print(s.minDeletionSize(strs))
