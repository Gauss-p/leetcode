maxNum = 100_001
modNum = 1_000_000_007
preSum = [0]*maxNum
curPos = 0
for i in range(1, maxNum):
    if (i&(-i)) == i:
        curPos += 1
    preSum[i] = ((preSum[i-1]<<curPos) | i)%modNum

class Solution:
    def concatenatedBinary(self, n: int) -> int:
        return preSum[n]

if __name__ == "__main__":
    s = Solution()
    n = 3
    print(s.concatenatedBinary(n))
