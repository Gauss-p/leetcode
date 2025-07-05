from typing import List
from collections import Counter

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        return max([k for k in cnt.keys() if k==cnt[k]]+[-1])

if __name__ == "__main__":
    s = Solution()
    arr = [2,2,3,4]
    print(s.findLucky(arr))
