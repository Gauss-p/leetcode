from typing import List

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        # n = len(nums)
        # for l in range(1,n+1):
        #     for i in range(n-l+1):
        #         cur_or = 0
        #         for j in range(i, i+l):
        #             cur_or = cur_or | nums[j]
        #         if cur_or >= k:
        #             return l
        # return -1
        def calc(orList):
            # 将数位列表orList转换成数字，与k进行比较
            tmp = 0
            for i in range(6):
                if orList[i]>=1:
                    tmp += (1<<i)
            return tmp
        orList = [0]*6 # 记录子数组中所有数字在各个位置上出现的次数
        n = len(nums)
        l,r = 0,0 # 窗口左端点和右端点，都包含
        res = float("inf")
        for r in range(n):
            # 首先在或值列表中加入右端点对应的数字
            orList = [orList[i]+((nums[r]>>i)&1) for i in range(6)]
            while l<=r and calc(orList)>=k:
                # 如果l没有超过r并且或值列表对应的数字还不小于k，那么就可以记录一次答案，并删除左端点对应的数字，为右端点的下一次滑动做准备
                res = min(res, r-l+1) # 记录答案
                orList = [orList[i]-((nums[l]>>i)&1) for i in range(6)] # 删除左端点
                l += 1 # 滑动左端点
        return -1 if res==float("inf") else res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    k = 2
    print(s.minimumSubarrayLength(nums, k))
