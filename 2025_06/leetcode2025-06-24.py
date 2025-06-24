from typing import List

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        # 对于每一个能够满足nums[i]=key的下标i，可以发现[i-k,i+k]都是满足条件的K近邻下标
        # 为了防止重复计算，我们始终维护一个上次加入的最右边的下标，并用i-k和上一次的最右边下标取最大值，这样就不会重复加入下标了
        n = len(nums)
        res = []
        r = 0
        for i in range(n):
            if nums[i] == key:
                l = max(i-k, r)
                r = min(n-1, i+k)+1
                res.extend(range(l, r))
        return res
        
        # n = len(nums)
        # res = []
        # for i in range(n):
        #     if nums[i] == key:
        #         for j in range(max(0, i-k), min(n-1, i+k)+1):
        #             if len(res) == 0 or j > res[-1]:
        #                 res.append(j)
        # return res

if __name__ == "__main__":
    s = Solution()
    nums = [3,4,9,1,3,9,5]
    key = 9
    k = 1
    print(s.findKDistantIndices(nums, key, k))
