from typing import List

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        newNums = sorted(nums, key = lambda x:(sum(list(map(int, list(str(x))))), x))
        pos1 = {v:i for i,v in enumerate(nums)}
        pos2 = {v:i for i,v in enumerate(newNums)}

        res = 0
        for k,p1 in pos1.items():
            p2 = pos2[k]
            if p1 == p2:
                continue
            pos1[k], pos1[nums[p2]] = p2, p1
            nums[p1], nums[p2] = nums[p2], nums[p1]
            res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [37,100]
    print(s.minSwaps(nums))
