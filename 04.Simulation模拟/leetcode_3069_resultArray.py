from typing import List

class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        res = nums[:2]
        pos = 0
        for i in nums[2:]:
            if res[pos] > res[-1]:
                pos += 1
                res.insert(pos, i)
            else:
                res.append(i)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,3]
    print(s.resultArray(nums))
