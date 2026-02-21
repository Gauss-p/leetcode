maxBits = 33
isPrime = [1]*maxBits
isPrime[0] = isPrime[1] = 0
for i in range(2, maxBits):
    if isPrime[i]==0:
        continue
    for j in range(i*2, maxBits, i):
        isPrime[j] = 0

maxNum = 1_000_001
preSum = [0]*(maxNum+1)
for i in range(maxNum):
    preSum[i+1] = preSum[i]+isPrime[i.bit_count()]

class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        return preSum[right+1]-preSum[left]

if __name__ == "__main__":
    s = Solution()
    left, right = 6, 10
    print(s.countPrimeSetBits(left, right))
