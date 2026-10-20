from typing import List
from math import sqrt

maxNum = 100001
factors = [[] for _ in range(maxNum)]
for i in range(1, maxNum):
    for j in range(1, int(sqrt(i))+1):
        if i%j == 0:
            factors[i].append(j)
            if j*j != i:
                factors[i].append(i//j)

class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        # 分析题目可以发现，如果整数k满足题目条件，那么一定需要满足：
        #   1.在划分后的n//k个子数组中，每个子数组内部的逆序对数量小于等于1；
        #   2.在划分后的n//k个子数组中，相邻两个子数组中后面一个的最小值大于等于前面一个的最大值;
        # 需要注意的是，在计算一个子数组内部的逆序对数量时还需要考虑开头和结尾的大小关系，因为当循环移动的时候,这两个数字就会变成相邻数字，若它们逆序了，则不满足要求
        n = len(nums)
        def check(k):
            mx = 0
            for i in range(0, n, k):
                curMax = 0
                invPairs = 0
                for j in range(i, i+k):
                    if nums[j] < mx: # 出现后面一个子数组中的元素小于前面一个子数组的最大值，即无法使nums有序
                        return False
                    if curMax < nums[j]:
                        curMax = nums[j]
                        
                    if j>i and nums[j-1] > nums[j]:
                        invPairs += 1
                        
                if mx < curMax:
                    mx = curMax

                if invPairs == 0: # 本身有序
                    continue

                if invPairs == 1 and nums[i+k-1]<=nums[i]: # 需要判断子数组开头结尾元素
                    continue

                return False

            return True

        res = 0
        for k in factors[n]:
            if check(k):
                res += k
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,1,2]
    print(s.sortableIntegers(nums))
