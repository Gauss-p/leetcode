from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        n = len(arrays)
        mx, mn = [], []
        for i in range(n):
            mx.append((arrays[i][-1], i))
            mn.append((arrays[i][0], i))
        mx.sort(reverse = True)
        mn.sort()
        i, j = 0, 0
        while i<n and mx[i][1] == mn[j][1]:
            i += 1
        res = abs(mx[i][0]-mn[j][0])
        i = 0
        while j<n and mx[i][1] == mn[j][1]:
            j += 1
        res = max(res, abs(mx[i][0]-mn[j][0]))
        return res

if __name__ == "__main__":
    s = Solution()
    arrays = [[1,2,3],[4,5],[1,2,3]]
    print(s.maxDistance(arrays))
