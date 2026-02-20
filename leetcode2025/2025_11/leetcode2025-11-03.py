from typing import List

class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        # 将颜色字符串分段，对于每一个连续的重复段进行计算，求出总的需要时间减去最大的需要时间即可得到最小的需要时间，累加即可
        n = len(colors)
        res = 0
        curMax, curSum = neededTime[0], neededTime[0]
        for i in range(1, n):
            if colors[i-1] != colors[i]:
                res += curSum-curMax
                curMax = neededTime[i]
                curSum = neededTime[i]
            else:
                if neededTime[i] > curMax:
                    curMax = neededTime[i]
                curSum += neededTime[i]
        return res+(curSum-curMax)

if __name__ == "__main__":
    s = Solution()
    colors = "abaac"
    neededTime = [1,2,3,4,5]
    print(s.minCost(colors, neededTime))
