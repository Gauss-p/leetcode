from typing import List

class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        # 首先分别求出两个数组的总和s1,s2和两个数组中0的数量z1,z2，贪心地想，如果要最小，那么我们只能将所有的0转成1，这时两个数组的和就分别为s1+z1和s2+z2，又因为我们需要让两个数组最终的和相等，并且此时两个数组都已经处于最小的状态，因此可以确定的是目标数组和target应为max(s1+z1,s2+z2)
        # 分情况讨论，先暂定s1+z1<s2+z2，所以我们需要做的是将nums1的总和增加到target，下面讨论两种情况，1.如果nums1中没有0，即z1=0，只能返回-1，否则可以返回target
        s1,s2 = sum(nums1), sum(nums2)
        z1,z2 = nums1.count(0), nums2.count(0)
        target = max(s1+z1, s2+z2)
        if (target>s1 and z1==0) or (target>s2 and z2==0):
            return -1
        return target

if __name__ == "__main__":
    s = Solution()
    nums1 = [3,2,0,1,0]
    nums2 = [6,5,0]
    print(s.minSum(nums1, nums2))
