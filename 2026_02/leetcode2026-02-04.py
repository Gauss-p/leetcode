from typing import List

class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        # 为了计算方便，我们将三段式数组分成第1段(单增)，第2段(单减)，第3段(单增)
        # 动态规划，定义数组f[i][0]表示以nums[i]为第1段的最后一个元素时的最大和
        #                  f[i][1]表示以nums[i]为第2段的最后一个元素时的最大和
        #                  f[i][2]表示以nums[i]为第3段的最后一个元素时的最大和
        # 因此答案就是对于所有索引i，f[i][2]的最大值
        # 接下来考虑转移方程
        # 当nums[i-1]<nums[i]时，说明[nums[i-1], nums[i]]构成一个单增数组，此时我们就可以将nums[i]作为第1段或第3段的最后一个元素：
        #   1.若我们将nums[i]作为第1段最后一个元素，那么nums[i-1]可以是第1段的开头，可以是第1段的最后一个元素，那么f[i][0] = max(nums[i-1], f[i-1][0])+nums[i]
        #   2.若我们将nums[i]作为第3段最后一个元素，那么nums[i-1]可以是第2段最后一个元素，也可以是第3段最后一个元素，因此f[i][2] = max(f[i-1][1], f[i-1][2])+nums[i]
        #   3.我们不能将它作为第2段的最后一个元素，因此f[i][1] = -inf

        # 当nums[i-1]>nums[i]时，说明[nums[i-1], nums[i]]构成一个单减数组，此时我们将nums[i]作为第2段最后一个元素
        #   1.将nums[i]作为第2段最后一个元素，那么nums[i-1]可以是第1段的结尾，也可以是第2段的结尾，因此f[i][1] = max(f[i-1][0], f[i-1][1])+nums[i]
        #   2.3.我们不能将nums[i]作为第1或第3段最后一个元素，因此f[i][0]=f[i][2]=-inf

        # 可以发现,f[i]的计算只与f[i-1]有关,因此我们可以将它压缩成3个数字进行计算

        res = -float("inf")
        f1, f2, f3 = [-float("inf")]*3
        n = len(nums)
        for i in range(n-1):
            x, y = nums[i], nums[i+1]
            # 先计算f3,再计算f2,最后计算f1,即可避免数据覆盖
            f3 = max(f2, f3)+y if x<y else -float("inf")
            f2 = max(f1, f2)+y if x>y else -float("inf")
            f1 = max(f1, x)+y if x<y else -float("inf")
            res = max(res, f3)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [0,-2,-1,-3,0,2,-1]
    print(s.maxSumTrionic(nums))
