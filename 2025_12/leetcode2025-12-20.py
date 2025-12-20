from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m, n = len(strs), len(strs[0])
        res = 0
        for j in range(n):
            for i in range(m-1):
                if strs[i][j] > strs[i+1][j]:
                    res += 1
                    break
        return res

if __name__ == "__main__":
    s = Solution()
    strs = ["cba","daf","ghi"]
    print(s.minDeletionSize(strs))
