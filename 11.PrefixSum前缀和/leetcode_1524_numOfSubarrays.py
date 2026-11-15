class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        n = len(arr)
        odd, even, preSum = 0, 1, 0
        modNum = 1_000_000_007
        res = 0
        for i in range(n):
            preSum += arr[i]
            if preSum & 1:
                res = (res+even)%modNum
                odd += 1
            else:
                res = (res+odd)%modNum
                even += 1
        return res

if __name__ == "__main__":
    s = Solution()
    arr = [1, 3, 5]
    print(s.numOfSubarrays(arr))
