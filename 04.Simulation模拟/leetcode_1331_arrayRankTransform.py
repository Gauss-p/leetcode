from typing import List

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        n = len(arr)
        pos = sorted(range(n), key = lambda x:arr[x])
        res = [0]*n
        cur = 0
        for i in range(n):
            if i == 0 or arr[pos[i]] != arr[pos[i-1]]:
                cur += 1
            res[pos[i]] = cur
        return res

if __name__ == "__main__":
    s = Solution()
    arr = [40,10,20,30]
    print(s.arrayRankTransform(arr))
