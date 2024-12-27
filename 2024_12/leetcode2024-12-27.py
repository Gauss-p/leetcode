from typing import List

class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        pos = []
        for i in range(len(nums)):
            if nums[i] == x:
                pos.append(i)
        res = [(pos[i-1] if i<=len(pos) else -1) for i in queries]
        return res

if __name__ == "__main__":
    s = Solution()
    nums, queries = [1,3,1,7], [1,3,2,4]
    x = 1
    print(s.occurrencesOfElement(nums, queries, x))
