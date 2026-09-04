class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        for i in range(n):
            cur = max(nums[:i+1])-min(nums[i:n])
            if cur <= k:
                return i
        return -1

if __name__ == "__main__":
    s = Solution()
    nums = [5,0,1,4]
    k = 3
    print(s.firstStableIndex(nums, k))
