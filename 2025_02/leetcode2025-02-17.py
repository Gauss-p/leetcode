from typing import List
from collections import defaultdict

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        dic = defaultdict(int)
        for i in arr: dic[i] += 1
        for k in dic:
            if 4*dic[k] > len(arr):
                return k
        return -1

if __name__ == "__main__":
    s = Solution()
    arr = [1,2,2,6,6,6,6,7,10]
    print(s.findSpecialInteger(arr))
