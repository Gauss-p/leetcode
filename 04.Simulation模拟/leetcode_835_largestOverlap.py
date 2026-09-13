from typing import List

class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        pos1 = [(i,j) for i in range(n) for j in range(n) if img1[i][j]]
        res = 0
        for i in range(-n+1, n):
            for j in range(-n+1, n):
                cur = 0
                for x,y in pos1:
                    nx, ny = x+i, y+j
                    if nx<0 or ny<0 or nx>=n or ny>=n:
                        continue
                    if img2[nx][ny]:
                        cur += 1
                res = max(res, cur)
        return res

if __name__ == "__main__":
    s = Solution()
    img1 = [[1,1,0],[0,1,0],[0,1,0]]
    img2 = [[0,0,0],[0,1,1],[0,0,1]]
    print(s.largestOverlap(img1, img2))
