class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        res = numBottles
        left = numBottles
        while left >= numExchange:
            res += (left//numExchange)
            left = left%numExchange+left//numExchange
        return res

if __name__ == "__main__":
    s = Solution()
    numBottles, numExchange = 9, 3
    print(s.numWaterBottles(numBottles, numExchange))
