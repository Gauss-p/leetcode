from typing import List

class Solution:
    def triangleType(self, nums: List[int]) -> str:
        a, b, c = sorted(nums)
        if a+b<=c:
            return "none"
        if a == b and b == c:
            return "equilateral"
        if a == b or b == c:
            return "isosceles"
        return "scalene"

if __name__ == "__main__":
    s = Solution()
    nums = [3,3,3]
    print(s.triangleType(nums))
