from typing import List
from collections import defaultdict

class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        # 根据题目可以发现，如果一个子数组中所有元素的异或结果是0，那么它就是一个美丽子数组，我们可以采用前缀和的思路，存储nums的前缀异或结果
        # 定义tmpXor用来存储nums的前缀异或结果，可以发现，如果nums[0:i]的异或结果和nums[0:j]的异或结果相同(i<j)，那么nums[i+1:j]一定是一个美丽子数组，因为Xor(nums[0:j])其实等于Xor(nums[0:i])^Xor(nums[i+1:j])，所以，如果Xor(nums[0:j])=Xor(nums[0:i])，就说明Xor(nums[i+1:j])=0，即nums[i+1:j]是美丽子数组
        # 我们同时定义一个字典cnt用来存储之前遇到过的所有前缀异或值的个数，这样，我们在每得到一个新的异或值tmpXor时，就可以直接根据上面的推导，将答案加上cnt[tmpXor]即可
        # 为了防止第一次遇到前缀异或值为0却没有加答案的情况，我们在最开始就将cnt[0]设置为1即可
        cnt = defaultdict(int)
        tmpXor = 0
        cnt[0] += 1
        res = 0
        for i in nums:
            tmpXor ^= i
            res += cnt[tmpXor]
            cnt[tmpXor] += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [4,3,1,2,4]
    print(s.beautifulSubarrays(nums))
