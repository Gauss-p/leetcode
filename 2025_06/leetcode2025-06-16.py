from typing import List

class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        # 对于每一个位置i，我们只需要知道nums[:i]的最小值即可求出以i为结尾的最大差值
        # 所以我们可以在循环中始终维护一个nums[:i]的最小值
        myMax = lambda x,y : x if x>y else y
        myMin = lambda x,y : x if x<y else y
        res = -1
        lastMin = float("inf")
        n = len(nums)
        for i in range(n):
            res = myMax(res, nums[i]-lastMin)
            lastMin = myMin(lastMin, nums[i])
        return -1 if res == 0 else res

        # res = -1
        # n = len(nums)
        # for i in range(n):
        #     for j in range(i+1, n):
        #         res = max(res, nums[j]-nums[i])
        # return -1 if res == 0 else res

if __name__ == "__main__":
    s = Solution()
    nums = [7,1,5,4]
    print(s.maximumDifference(nums))
