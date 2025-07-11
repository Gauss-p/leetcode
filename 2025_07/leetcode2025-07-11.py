from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        # 合并所有重叠区间，用总时长days减去所有的合并后的区间长度总和即可
        n = len(meetings)
        meetings.sort()
        tot = []
        for i in range(n):
            if len(tot)==0 or meetings[i][0]>tot[-1][1]:
                tot.append(meetings[i])
            else:
                tot[-1][1] = max(tot[-1][1], meetings[i][1])
        res = days
        for i in tot:
            res -= (i[1]-i[0]+1)
        return res

if __name__ == "__main__":
    s = Solution()
    days = 10
    meetings = [[5,7],[1,3],[9,10]]
    print(s.countDays(days, meetings))
