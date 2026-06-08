from typing import List

class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        res1, res2, res3 = [], [], []
        for i in nums:
            if i < pivot:
                res1.append(i)
            elif i == pivot:
                res2.append(i)
            else:
                res3.append(i)
        return res1+res2+res3

if __name__ == "__main__":
    s = Solution()
    nums = [9,12,5,10,14,3,10]
    pivot = 10
    print(s.pivotArray(nums, pivot))
