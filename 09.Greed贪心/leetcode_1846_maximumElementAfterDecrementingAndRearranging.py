from typing import List

class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        cur = 1
        for i in arr[1:]:
            cur = min(cur+1, i)
        return cur

if __name__ == "__main__":
    s = Solution()
    arr = [2,2,1,2,1]
    print(s.maximumElementAfterDecrementingAndRearranging(arr))
