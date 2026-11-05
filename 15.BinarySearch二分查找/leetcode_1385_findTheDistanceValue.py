from typing import List
from bisect import *

class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr2.sort()
        res = 0
        for i in arr1:
            mn = i-d
            l = bisect_left(arr2, mn)
            if l<len(arr2) and arr2[l]-i <= d:
                continue
            res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    arr1 = [4,5,8]
    arr2 = [10,9,1,8]
    d = 2
    print(s.findTheDistanceValue(arr1, arr2, d))
