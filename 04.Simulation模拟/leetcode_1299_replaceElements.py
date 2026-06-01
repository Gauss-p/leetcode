from typing import List

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n = len(arr)
        tmpMax = arr[n-1]
        res = [-1]*n
        for i in range(n-2, -1, -1):
            res[i] = tmpMax
            tmpMax = max(tmpMax, arr[i])
        return res

if __name__ == "__main__":
    s = Solution()
    arr = [17,18,5,4,6,1]
    print(s.replaceElements(arr))
