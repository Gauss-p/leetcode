from typing import List

class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort(reverse = True)
        res = 0
        s = sum(apple)
        tot = 0
        for i in capacity:
            if tot >= s:
                return res
            tot += i
            res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    apple = [1,3,2]
    capacity = [4,3,1,5,2]
    print(s.minimumBoxes(apple, capacity))
