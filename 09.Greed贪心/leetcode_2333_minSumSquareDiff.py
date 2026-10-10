from typing import List
from collections import Counter

class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        n = len(nums1)
        diff = []
        for i in range(len(nums1)):
            diff.append(abs(nums1[i]-nums2[i]))
        cnt = Counter(diff)
        diff = []
        for i in cnt:
            diff.append([i, cnt[i]])
        diff.sort(reverse = True)

        k = k1+k2
        while k and diff[0][0] > 0:
            if diff[0][1] < k:
                k -= diff[0][1]
                diff[0][0] -= 1
                if len(diff) >= 2 and diff[0][0] == diff[1][0]:
                    diff[1][1] += diff[0][1]
                    diff.pop(0)
            else:
                diff[0][1] -= k
                diff.append([diff[0][0]-1, k])
                k = 0
        
        return sum(i[0]*i[0]*i[1] for i in diff)

if __name__ == "__main__":
    s = Solution()
    nums1 = [1,4,10,12]
    nums2 = [5,8,6,9]
    k1, k2 = 1, 1
    print(s.minSumSquareDiff(nums1, nums2, k1, k2))
