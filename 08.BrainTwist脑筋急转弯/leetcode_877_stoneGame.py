from typing import List

class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True
        # n = len(piles)
        # @cache
        # def dfs(l, r, turn):
        #     if l == r:
        #         return piles[l]*turn
        #     resL = piles[l]*turn+dfs(l+1, r, -turn)
        #     resR = piles[r]*turn+dfs(l, r-1, -turn)
        #     return max(resL*turn, resR*turn)*turn
        # return dfs(0, n-1, 1) > 0

if __name__ == "__main__":
    s = Solution()
    piles = [5,3,4,5]
    print(s.stoneGame(piles))
