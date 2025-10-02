class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        res = numBottles
        left = numBottles
        while left >= numExchange:
            res += 1
            left = left-numExchange+1
            numExchange += 1
        return res

if __name__ == "__main__":
    s = Solution()
    numBottles = 13
    numExchange = 6
    print(s.maxBottlesDrunk(numBottles, numExchange))
