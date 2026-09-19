class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # x∈[x1,x2], y∈[y1,y2], (x-xCenter)**2+(y-yCenter)**2最小
        x = x1 if xCenter<x1 else (x2 if x2<xCenter else xCenter)
        y = y1 if yCenter<y1 else (y2 if y2<yCenter else yCenter)
        return (xCenter-x)**2 + (yCenter-y)**2 <= radius*radius

if __name__ == "__main__":
    s = Solution()
    radius, xCenter, yCenter = 1, 0, 0
    x1, y1, x2, y2 = 1, -1, 3, 1
    print(s.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2))
