from typing import List
from collections import defaultdict

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        res = len(fruits)
        n = len(fruits)
        used = defaultdict(int)
        for i in range(n):
            for j in range(n):
                if used[j]==0 and baskets[j]>=fruits[i]:
                    used[j] = 1
                    res -= 1
                    break
        return res

if __name__ == "__main__":
    s = Solution()
    fruits = [4,2,5]
    baskets = [3,5,4]
    print(s.numOfUnplacedFruits(fruits, baskets))
