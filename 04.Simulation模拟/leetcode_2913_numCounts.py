from typing import List

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for i in range(n):
            st = set()
            for j in range(i, n):
                st.add(nums[j])
                res += len(st)*len(st)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,1]
    print(s.sumCounts(nums))
