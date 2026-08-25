from typing import List

class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        st = set(nums)
        i = k
        while i in st:
            i += k
        return i

if __name__ == "__main__":
    s = Solution()
    nums = [8,2,3,4,6]
    k = 2
    print(s.missingMultiple(nums, k))
