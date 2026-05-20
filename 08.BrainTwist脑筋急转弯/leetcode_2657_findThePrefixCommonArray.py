from typing import List

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        res = [0]*n
        res[-1] = n
        cnt = set()
        cur = n
        for i in range(n-1, 0, -1):
            a, b = A[i], B[i]
            if a not in cnt:
                cnt.add(a)
                cur -= 1
            if b not in cnt:
                cnt.add(b)
                cur -= 1
            res[i-1] = cur
        return res

if __name__ == "__main__":
    s = Solution()
    A, B = [1,3,2,4], [3,1,2,4]
    print(s.findThePrefixCommonArray(A,B))
