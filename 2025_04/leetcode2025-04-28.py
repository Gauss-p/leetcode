from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        # 滑动窗口，自动遍历左端点，手动滑动右端点，需要注意的是在求出每一个右端点后需要进行判断，如果此时窗口的分数大于等于k，那么说明此时的右端点是不能取的，答案只能累加r-l-1，否则答案可以累加r-l
        # 如果自动遍历右端点，手动滑动左端点，那么每次求出左端点后答案都可以加上r-l+1
        n = len(nums)
        curSum = 0
        r = 0
        res = 0
        for l in range(n):
            while curSum*(r-l) < k and r<n:
                curSum += nums[r]
                r += 1
            res += r-l
            if curSum*(r-l) >= k:
                res -= 1
            curSum -= nums[l]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,4,3,5]
    k = 10
    print(s.countSubarrays(nums, k))
