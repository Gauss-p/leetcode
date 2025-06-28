from typing import List

class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        # 先将nums中的值从大到小排序，我们需要选的就是前k个，但是由于题目要求的是子序列，所以要保证元素的相对顺序不改变，就需要保存每一个元素的下标，再次进行排序，最后取出每一个下标对中的元素即可
        keyVals = [(nums[i], i) for i in range(len(nums))]
        keyVals.sort(reverse = True)
        return [kv[0] for kv in sorted(keyVals[:k], key = lambda x:x[1])]

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,3,3]
    k = 2
    print(s.maxSubsequence(nums, k))
