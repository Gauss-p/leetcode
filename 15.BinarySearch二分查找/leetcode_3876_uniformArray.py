from bisect import *
from sortedcontainers import SortedList

class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        cnt = SortedList()
        for i in nums1:
            if i&1:
                cnt.add(i)
        def calc(x):
            for i in nums1:
                if i%2 == x:
                    continue
                indx = cnt.bisect_left(i)-1
                if indx<0 or i-cnt[indx]<1:
                    return False
            return True
        return calc(0) or calc(1)

if __name__ == "__main__":
     s = Solution()
     nums = [1,4,7]
     print(s.uniformArray(nums))
