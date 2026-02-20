from typing import List

MODNUM = 1_000_000_007
MAX_NUM = 100001
pow2 = [1]*MAX_NUM
for i in range(1, MAX_NUM):
    pow2[i] = (pow2[i-1]*2)%MODNUM

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        # 排序后，用双指针求出所有合法的最小值和最大值，求所有合法的最大最小值思路如下：首先定义左右指针，对应最小最大值，然后，如果nums[l]+nums[r]<=target，我们就记录答案，同时将左端点l向右移动，否则就将右端点向左移动
        # 每次记录答案时，我们就将最小值固定，只要最大值不超过r就可以了，那么对于[l+1,r]这个区间内，每一个元素都有选或不选两种情况，那么答案就需要加上2**(r-(l+1)+1)=2**(r-l)
        # 我们可以直接使用python内置的pow函数来求，也可以预处理所有的pow(2,n)的数字，后者空间更大，时间更少
        nums.sort()
        left, right = 0, len(nums)-1
        res = 0
        # modNum = 1_000_000_007
        while left<=right:
            if nums[left]+nums[right]<=target:
                # res = (res+pow(2, right-left, modNum))%modNum
                res = (res+pow2[right-left])%MODNUM
                left += 1
            else:
                right -= 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,3,3,4,6,7]
    target = 12
    print(s.numSubseq(nums, target))
