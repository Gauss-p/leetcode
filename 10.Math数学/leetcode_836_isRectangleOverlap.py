from typing import List

class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        hor = min(rec1[2], rec2[2])-max(rec1[0], rec2[0])
        ver = min(rec1[3], rec2[3])-max(rec1[1], rec2[1])
        return hor > 0 and ver > 0

if __name__ == "__main__":
    s = Solution()
    rec1 = [0,0,1,1]
    rec2 = [2,2,3,3]
    print(s.isRectangleOverlap(rec1, rec2))
