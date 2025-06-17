from typing import List

class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        # 将nums直接排序，那么对于每一个位置，和它差值最小的数字就是最靠近它的数字
        # 因此，如果某一个位置i和i+2对应的数字差值小于等于k，那么nums[i:i+3]就是一个满足最大差限制的三元组，将其加入答案，之后就需要将i转移到i+3。而如果i和i+2对应的数字差值大于k，那么nums[i:i+3]不可能构成一个满足条件的三元组，但是i之前的所有数字都已经计算过了，而i+2之后的数字只可能更大，因此这时我们就应返回空列表，不可能满足条件
        # 然后从0开始计算即可
        nums.sort()
        n = len(nums)
        res = []
        for i in range(0, n, 3):
            if nums[i+2]-nums[i] > k:
                return []
            else:
                res.append(nums[i:i+3])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,4,8,7,9,3,5,1]
    k = 2
    print(s.divideArray(nums, k))
