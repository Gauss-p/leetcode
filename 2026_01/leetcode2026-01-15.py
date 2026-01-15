from typing import List

class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        hBars.sort()
        vBars.sort()
        def maxContinue(lst):
            lst.append(float("inf"))
            length = len(lst)
            ans = 0
            last = 0
            for i in range(1, length):
                if lst[i]-lst[i-1] != 1:
                    ans = max(ans, i-last)
                    last = i
            return ans
        
        edge = min(maxContinue(hBars)+1, maxContinue(vBars)+1)
        return edge*edge

if __name__ == "__main__":
    s = Solution()
    n = 2
    m = 1
    hBars = [2,3]
    vBars = [2]
    print(s.maximizeSquareHoleArea(n, m, hBars, vBars))
