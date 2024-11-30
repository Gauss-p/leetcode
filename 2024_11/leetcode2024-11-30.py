class Solution:
    def canAliceWin(self, nums: list[int]) -> bool:
        tot, one = 0, 0
        for i in nums:
            if i<10:
                one += i
            tot += i
        return 2*one != tot

if __name__ == "__main__":
    s = Solution()
    nums = [5,5,5,25]
    print(s.canAliceWin(nums))
