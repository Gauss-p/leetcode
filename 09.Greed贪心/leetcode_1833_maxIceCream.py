from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        mx = max(costs)
        tot = [0]*(mx+1)
        for i in costs:
            tot[i] += 1
        
        res = 0
        for i in range(1, mx+1):
            if coins < i:
                break
            cnt = min(coins//i, tot[i])
            res += cnt
            coins -= i*cnt
        return res

if __name__ == "__main__":
    s = Solution()
    costs = [1,3,2,4,1]
    coins = 7
    print(s.maxIceCream(costs, coins))
