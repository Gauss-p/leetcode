
class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        sufMin = [10**18]*(n+1)
        for i in range(n):
            sufMin[n-i-1] = min(sufMin[n-i], nums[n-i-1])

        mx = 0
        for i in range(n):
            mx = max(mx, nums[i])
            if mx-sufMin[i] <= k:
                return i
        return -1

if __name__ == "__main__":
    s = Solution()
    nums = [5,0,1,4]
    k = 3
    print(s.firstStableIndex(nums, k))
