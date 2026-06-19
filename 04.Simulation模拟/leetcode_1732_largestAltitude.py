from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        res = 0
        cur = 0
        for i in gain:
            cur += i
            res = max(res, cur)
        return res

if __name__ == "__main__":
    s = Solution()
    gain = [-5,1,5,0,-7]
    print(s.largestAltitude(gain))
