from typing import List

class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        neg, pos = [], []
        zero = (nums.count(0) > 0)
        for i in nums:
            if i<0:
                neg.append(i)
            else:
                pos.append(i)
        neg.sort()
        pos.sort()
        res1, res2, res3 = -10**18, -10**18, -10**18
        res4 = 0 if zero else -10**18
        if len(pos) >= 3:
            res1 = pos[-1]*pos[-2]*pos[-3]
        if len(pos) >= 1 and len(neg) >= 2:
            res2 = pos[-1]*neg[0]*neg[1]
        if len(neg) >= 3:
            res3 = neg[-1]*neg[-2]*neg[-3]
        return max(res1, res2, res3, res4)

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.maximumProduct(nums))
