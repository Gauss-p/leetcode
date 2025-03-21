from typing import List

class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        # 为了使答案最大，我们尽可能地将k个2全部乘到一个数字上，并将其与其他所有数字相或
        # 但是这个数字不一定是最大值，所以我们将所有数字都按上述操作求出答案后取最大值即可
        # 为了避免重复计算，用前缀或值和后缀或值来存储，需要的时候取出计算好的值，前后相或就行
        n = len(nums)
        pre, aft = [0]*(n+1), [0]*(n+1)
        for i in range(n):
            pre[i+1] = pre[i]|nums[i]
            aft[n-i-1] = aft[n-i]|nums[n-i-1]
        res = 0
        for i in range(n):
            tmp = pre[i]|aft[i+1]|(nums[i]<<k)
            res = max(res, tmp)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [12,9]
    k = 1
    print(s.maximumOr(nums, k))
