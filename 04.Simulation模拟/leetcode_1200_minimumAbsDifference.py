from typing import List

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        res = []
        minDiff = float("inf")
        for i in range(len(arr)-1):
            curDiff = arr[i+1]-arr[i]
            if curDiff < minDiff:
                minDiff = curDiff
                res = [[arr[i], arr[i+1]]]
            elif curDiff == minDiff:
                res.append([arr[i], arr[i+1]])
        return res

if __name__ == "__main__":
    s = Solution()
    arr = [4,2,1,3]
    print(s.minimumAbsDifference(arr))
