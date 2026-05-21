from typing import List
from collections import defaultdict

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        n = len(arr1)
        cnt = defaultdict(int)
        for i in range(n):
            cur = ""
            for j in str(arr1[i]):
                cur += j
                cnt[cur] = 1
        
        res = 0
        for i in range(len(arr2)):
            cur = str(arr2[i])
            for _ in range(len(cur)):
                if cur in cnt:
                    res = max(res, len(cur))
                    break
                cur = cur[:-1]
        return res

if __name__ == "__main__":
    s = Solution()
    arr1 = [1,10,100]
    arr2 = [1000]
    print(s.longestCommonPrefix(arr1, arr2))
