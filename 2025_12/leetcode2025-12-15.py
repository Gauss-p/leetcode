from typing import List

class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        prices.append(float("inf"))
        n = len(prices)
        res = 0
        last = 0
        for i in range(n-1):
            if prices[i]-1 != prices[i+1]:
                length = i-last+1
                res += (1+length)*length//2
                last = i+1
        return res

if __name__ == "__main__":
    s = Solution()
    prices = [3,2,1,4]
    print(s.getDescentPeriods(prices))
