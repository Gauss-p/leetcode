from typing import List

class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse = True)
        res = 0
        for i in range(0, len(cost), 3):
            res += cost[i]
            if i+1 < len(cost):
                res += cost[i+1]
        return res

if __name__ == "__main__":
    s = Solution()
    cost = [1,2,3]
    print(s.minimumCost(cost))
