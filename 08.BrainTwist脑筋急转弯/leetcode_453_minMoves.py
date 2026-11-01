from typing import List

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        # n-1个元素加1相当于一个元素减1
        mn = min(nums)
        return sum(i-mn for i in nums)

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.minMoves(nums))
