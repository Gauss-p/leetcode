from typing import List

class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        # 贪心地想，我们要让最大差值的最小值尽可能小，就要尽可能地从最小差值开始寻找。
        # 我们将nums从小到大排序，那么对于每一个数字，在nums的其他数字中，和该数字的差值最小的就是在它的左右两边的两个数字，所以，我们可以将排序后的每一个间隔看作是当前的最小差值
        # 接下来用二分查找的方法寻找答案，那么我们需要一个check函数来确定当前的左右端点应如何变化。定义check(mx)返回值是：在nums中能否找到至少p个数对的差值小于等于mx，那么我们可以查找每一个间隔，如果i和i+1对应的数字之间的差值小于等于mx，那么我们就记录一个满足条件的差值，同时将i加2，跳过该间隔，否则就将i加1，继续寻找间隔
        nums.sort()
        n = len(nums)
        def check(mx):
            # 判断函数
            cnt = 0
            i = 0
            while i<n-1:
                if abs(nums[i]-nums[i+1]) <= mx:
                    # 可以选择该间隔
                    cnt += 1
                    i += 2
                else:
                    i += 1
            return cnt >= p

        l, r = 0, max(nums)-min(nums)
        while l<r:
            mid = (l+r)//2
            if check(mid):
                r = mid
            else:
                l = mid+1
        return l

if __name__ == "__main__":
    s = Solution()
    nums = [10,1,2,7,1,3]
    p = 2
    print(s.minimizeMax(nums, p))
