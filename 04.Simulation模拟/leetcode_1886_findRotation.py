from typing import List

class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n = len(mat)
        def rotate(mat):
            newMat = [[0]*n for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    newMat[i][j] = mat[n-j-1][i]
            return newMat
        
        for _ in range(4):
            if mat == target:
                return True
            mat = rotate(mat)
        return False

if __name__ == "__main__":
    s = Solution()
    mat = [[0,1],[1,0]]
    target = [[1,0],[0,1]]
    print(s.findRotation(mat, target))
