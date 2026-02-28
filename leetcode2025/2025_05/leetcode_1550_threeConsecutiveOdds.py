from typing import List

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        arr = [i%2 for i in arr]
        n = len(arr)
        for i in range(1,n-1):
            if arr[i-1]+arr[i]+arr[i+1]==3:
                return True
        return False

if __name__ == "__main__":
    s = Solution()
    arr = [1,2,34,3,4,5,7,23,12]
    print(s.threeConsecutiveOdds(arr))
