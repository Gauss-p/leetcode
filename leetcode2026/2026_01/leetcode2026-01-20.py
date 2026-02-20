from typing import List

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        # 题目中给出的运算：ans[i] OR (ans[i] + 1) == nums[i] 相当于将ans[i]的最右侧一个0位置变成1
        # 因此，用逆运算，将nums中每一个值都进行以下操作即可：将其最右侧一个0右边一个位置从1改为0，若最右侧0已经位于最后一个位置，则res中对应值为-1
        res = []
        for i in nums:
            cur = ((i^(i+1))+1)>>2
            if cur == 0:
                res.append(-1)
            else:
                res.append(i-cur)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,3,5,7]
    print(s.minBitwiseArray(nums))
