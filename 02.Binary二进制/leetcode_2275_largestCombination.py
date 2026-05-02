from typing import List

class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        res = 0
        for i in range(32):
            tmp = 0
            for c in candidates:
                if (c>>i)&1 == 1:
                    tmp += 1
            res = max(res, tmp)
        return res

if __name__ == "__main__":
    s = Solution()
    candidates = [16,17,71,62,12,24,14]
    print(s.largestCombination(candidates))
