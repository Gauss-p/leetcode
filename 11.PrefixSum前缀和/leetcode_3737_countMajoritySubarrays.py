from typing import List
from sortedcontainers import SortedList

class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        preSum = [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+(nums[i]==target)

        # 合法区间[l,r)满足：
        #   2*(preSum[r]-preSum[l]) > r-l
        # 故对于一个不包含在区间内的右端点r，其左端点就应当满足：
        #   2*preSum[l]-l < 2*preSum[r]-r
        # 即可用有序列表+二分查找解决问题

        stl = SortedList()
        res = 0
        for i in range(n):
            stl.add(2*preSum[i]-i)
            cur = 2*preSum[i+1]-(i+1)
            indx = stl.bisect_left(cur)
            res += indx
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,2,3]
    target = 2
    print(s.countMajoritySubarrays(nums, target))
