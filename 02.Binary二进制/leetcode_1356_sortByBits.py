from typing import List

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key = lambda x:(x.bit_count(), x))

if __name__ == "__main__":
    s = Solution()
    arr = [0,1,2,3,4,5,6,7,8]
    print(s.sortByBits(arr))
