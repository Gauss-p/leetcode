class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        part = minutes/60
        hd = (hour*30+30*part)%360
        md = minutes*6
        res = abs(hd-md)
        return min(res, 360-res)

if __name__ == "__main__":
    s = Solution()
    hour, minutes = 12, 30
    print(s.angleClock(hour, minutes))
