class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        mx, mn = max(need1, need2), min(need1, need2)
        return min(cost1*need1+cost2*need2, costBoth*mx, costBoth*mn+(need1-mn)*cost1+(need2-mn)*cost2)

if __name__ == "__main__":
    s = Solution()
    cost1 = 3
    cost2 = 2
    costBoth = 1
    need1 = 3
    need2 = 2
    print(s.minimumCost(cost1, cost2, costBoth, need1, need2))
