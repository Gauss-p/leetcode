from typing import List

class Solution:
    def sumZero(self, n: int) -> List[int]:
        return list(range(-(n//2), 0, 1)) + [0]*(n%2) + list(range(1, n//2+1))

if __name__ == "__main__":
    s = Solution()
    n = 5
    print(s.sumZero(n))
