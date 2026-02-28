from typing import List

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        # 方法一，通过观察三元组值的计算公式，可以发现nums[i]要尽可能大，nums[k]也要尽可能大，所以提前计算每个位置之前的最大值和之后的最大值即可
        pre, aft = [0]*(n+1), [0]*(n+1)
        for i in range(n):
            pre[i+1] = max(pre[i], nums[i])
            aft[n-i-1] = max(aft[n-i], nums[n-i-1])
        for i in range(n):
            res = max(res, (pre[i]-nums[i])*aft[i+1])
        return res
        # 方法二，暴力
        # res = 0
        # n = len(nums)
        # for i in range(n):
        #     for j in range(i+1, n):
        #         for k in range(j+1, n):
        #             res = max(res, (nums[i]-nums[j])*nums[k])
        # return res

if __name__ == "__main__":
    s = Solution()
    nums = [12,6,1,2,7]
    print(s.maximumTripletValue(nums))
