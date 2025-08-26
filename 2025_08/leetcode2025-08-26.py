from typing import List

class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        diagonal = 0
        area = 0
        for a,b in dimensions:
            cur = a*a+b*b
            if cur > diagonal:
                diagonal = cur
                area = a*b
            elif cur == diagonal:
                if a*b > area:
                    area = a*b
        return area

if __name__ == "__main__":
    s = Solution()
    dimensions = [[9,3],[8,6]]
    print(s.areaOfMaxDiagonal(dimensions))
