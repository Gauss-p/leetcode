from typing import List

class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        if colors[0] != colors[-1]:
            return n-1
        res = 0
        def calc(start, end, space):
            for i in range(start, end, space):
                if colors[i] != colors[0]:
                    return i
        return max(n-1-calc(1, n, 1), calc(n-2, -1, -1))

if __name__ == "__main__":
    s = Solution()
    colors = [1,1,1,6,1,1,1]
    print(s.maxDistance(colors))
