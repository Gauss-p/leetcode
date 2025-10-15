from typing import List

class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        # 保存上一个连续递增段的长度和当前一个连续递增段的长度，每次记录两个连续递增段的最大值，即可得到最大可能的k值，用答案和它取最大值即可。同时需要防止一个连续段过长，可以分成两个递增段的情况，因此还需要取当前连续递增段的长度的一半来记录答案，即将答案和当前连续递增段长度的一半取最大值
        last, cur, res = 0, 1, 0
        n = len(nums)
        for i in range(1, n):
            if nums[i-1] < nums[i]:
                cur += 1
            else:
                last = cur
                cur = 1
            res = max(res, min(last, cur)) # 前后两个连续段均选
            res = max(res, cur//2) # 当前连续段过长
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,5,7,8,9,2,3,4,3,1]
    print(s.maxIncreasingSubarrays(nums))
