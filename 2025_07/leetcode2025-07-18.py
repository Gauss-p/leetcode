from typing import List
from heapq import *

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        # 题目的本质是先将nums分成前后两个部分，然后在前后分别选n个数字，求所有选择方案中的差值最小值。贪心的想，如果要让前面的n个数字的和减去后面的n个数字的和最小，最好就是让前面n个数字最小，后面n个数字最大，因此对于每一种分割方式，我们只需找出前面部分的最小n个数字之和和后面部分最大n个数字之和，作差即可得到当前情况下的最优答案
        # 求最小n个数和最大n个数可以考虑小根堆和大根堆，我们只需要在循环中对于每一个数字，先加入堆中，再弹出堆顶元素，就可以始终保持相同个数的最小数字
        # 为了方便计算，我们可以采用前缀最小值和后缀最大值来存储所有用堆计算出来的和，然后对于每一种分割情况就可以用O(1)的时间直接求出当前的最优答案
        m = len(nums)
        n = m//3
        preMin = [float("inf")]*(m+1) # 前缀最小值，preMin[i]表示nums[:i]中的最小n个数字之和
        preMin[n] = sum(nums[:n])
        curNums = []
        curSum = 0
        for i in range(n):
            curSum += nums[i]
            heappush(curNums, -nums[i]) # python默认大根堆，但我们需要小根堆，因此用负数代替
        # 小根堆，每次弹出最大值
        for i in range(n, 3*n):
            curSum += nums[i] # 直接维护n个数字之和，就不需要每次用sum计算，这样就可以节省时间(用sum其实会超时)
            heappush(curNums, -nums[i])
            curSum -= (-heappop(curNums))
            preMin[i+1] = min(preMin[i], curSum)

        sufMax = [0]*(m+1) # 后缀最大值，其中sufMax[i]表示nums[i:]中最大n个数字之和
        sufMax[2*n] = sum(nums[2*n:])
        curSum = 0
        curNums = []
        for i in range(2*n, m):
            curSum += nums[i]
            heappush(curNums, nums[i])
        for i in range(2*n-1, -1, -1):
            curSum += nums[i]
            heappush(curNums, nums[i])
            curSum -= heappop(curNums)
            sufMax[i] = max(sufMax[i+1], curSum)
        
        res = float("inf")
        for i in range(n, 2*n+1):
            # 注意preMin[i]不包含i，sufMax[i]包含i
            res = min(res, preMin[i]-sufMax[i])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [7,9,5,8,1,3]
    print(s.minimumDifference(nums))
