from typing import List

class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.append(bottom-1)
        special.append(top+1)
        special.sort()
        res = 0
        for i in range(1,len(special)):
            if res<special[i]-special[i-1]-1:
                res = special[i]-special[i-1]-1
        return res

if __name__ == "__main__":
    s = Solution()
    bottom, top = 2, 9
    special = [4,6]
    print(s.maxConsecutive(bottom, top, special))
