from typing import List

class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        return list(map(int, list(''.join(list(map(str, nums))))))

if __name__ == "__main__":
    s = Solution()
    nums = [13,25,83,77]
    print(s.separateDigits(nums))
