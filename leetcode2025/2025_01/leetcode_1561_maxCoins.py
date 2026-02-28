from typing import List

class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        # 为了让我取到的硬币数量最大，就需要让Bob和Alice取到的硬币数量最小。
        # 对于Bob，就让他取走数量最小的n堆即可
        # 对于Alice和我，就在剩下的2n堆里选，Alice先选最大，我再选次大，Alice再选最大，我再选次大，以此类推，一直到所有硬币都被选完
        # 这样，我就能取到最多硬币
        piles.sort()
        n = len(piles)//3
        res = 0
        for i in range(n, 3*n, 2):
            res += piles[i]
        return res

if __name__ == "__main__":
    s = Solution()
    piles = [2,4,1,2,7,8]
    print(s.maxCoins(piles))
