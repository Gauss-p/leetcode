from typing import List

class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n//2+1):
            j = n-i
            if '0' not in str(i) and '0' not in str(j):
                return [i,j]
        return []

if __name__ == "__main__":
    s = Solution()
    n = 2
    print(s.getNoZeroIntegers(n))
