from typing import List

class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        res = [0,0]
        n = len(mat)
        for i in range(n):
            cnt = mat[i].count(1)
            if cnt>res[1]:
                res[0] = i
                res[1] = cnt
        return res

if __name__ == "__main__":
    s = Solution()
    mat = [[0,1],[1,0]]
    print(s.rowAndMaximumOnes(mat))
