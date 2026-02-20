from typing import List

class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        # 贪心，将nums从小到大排序，然后将nums最小的数字减去k，从这个值开始，每一次往后排的时候就加1，然后看下一个值是否可以通过加或减k取得即可
        nums.sort()
        nums[0] -= k
        res = 1
        for i in range(1, len(nums)):
            nums[i] = min(max(nums[i-1]+1, nums[i]-k), nums[i]+k)
            if nums[i] != nums[i-1]:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,2,3,3,4]
    k = 2
    print(s.maxDistinctElements(nums, k))
