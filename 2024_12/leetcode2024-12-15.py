from typing import List
from collections import Counter

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        res,tot = 0,0
        for i,c in cnt.most_common():
            res += 1
            tot += c
            if tot >= len(arr)//2:
                break
        return res

if __name__ == "__main__":
    s = Solution()
    arr = [3,5,3,5,3,3,2,7,5,2]
    print(s.minSetSize(arr))
