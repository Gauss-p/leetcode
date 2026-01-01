from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        add = 1
        for i in range(n-1, -1, -1):
            if add == 0:
                break
            if digits[i] <= 8:
                digits[i] += 1
                add = 0
            else:
                digits[i] = 0
        if add == 1:
            digits.insert(0, 1)
        return digits

if __name__ == "__main__":
    s = Solution()
    digits = [1,2,3]
    print(s.plusOne(digits))
