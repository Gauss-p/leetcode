from typing import List
from collections import defaultdict

class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        mx = max(item[0] for item in items)
        cnt = [0]*(mx+1)
        for item in items:
            cnt[item[0]] += 1
        
        multipleCnt = [0]+[sum(cnt[i::i])-1 for i in range(1, mx+1)]
        minPrice = min(item[1] for item in items)
        cheap = defaultdict(int)
        for fac, price in items:
            if multipleCnt[fac] and price < minPrice*2:
                cheap[price] += multipleCnt[fac]
        
        stl = sorted(cheap.items())
        res = 0
        for price, curNum in stl:
            canBuy = min(budget//price, curNum)
            res += canBuy*2
            budget -= canBuy*price
            if canBuy < curNum:
                break
        return res+(budget//minPrice)

if __name__ == "__main__":
    s = Solution()
    items = [[1, 6], [2, 4], [3, 5]]
    budget = 19
    print(s.maximumSaleItems(items, budget))
