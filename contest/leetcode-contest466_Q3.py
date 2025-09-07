from typing import List

class Solution:
    def bowlSubarrays(self, nums: List[int]) -> int:
        # 注意：题目中要求的碗子数组有如下要求：左右端点的值都大于中间所有元素的最大值，因此，形似：[3,2,1,2]的子数组并不能称为一个碗子数组
        # 因此，对于每一个位置，我们考虑它作为碗底的情况是否存在。那么分析题目可以知道，如果要让一个位置作为碗底，必须要在其左侧找到一个大于该值的数字，并在其右侧找到一个大于该值的数字，同时还需要保证在两者之间没有任何一个数字的值能够超过两侧的数值。定义两个数组L和R，其中L[i]代表i左侧的大于nums[i]的数字位置，同时保证两者之间没有大于左侧数字的数，R[i]代表i右侧的大于nums[i]的数字位置，同时保证两者之间没有大于右侧数字的数。那么在计算完成之后，只要一个位置i在L和R中都有对应的合法的索引，我们就可以记录一个碗了
        # 接下来，如何计算L和R数组呢？先计算L数组，由于我们需要保证位置i对应的L[i]位置满足以下两个条件：nums[L[i]]>nums[i]，且nums[L[i]]>max(nums[L[i]+1, i+1])，因此可以想到利用单调栈，我们只需要在正序遍历的同时维护一个单调递增的单调栈，那么"弹出之前小于当前位置的数字"这个操作就可以保证i找到的L[i]一定满足第二个条件。同样的，我们只需要倒序遍历的同时维护一个单增的单调栈，也可以计算出我们要的R数组
        n = len(nums)
        L = [0]*n
        R = [0]*n
        stack = [] # 单调栈
        for i in range(n):
            while stack and nums[stack[-1]] < nums[i]:
                stack.pop()
            L[i] = -1 if len(stack)==0 else stack[-1] # -1用来标记没有合法左端点
            stack.append(i)

        stack = []
        for i in range(n-1, -1, -1):
            while stack and nums[stack[-1]] < nums[i]:
                stack.pop()
            R[i] = n if len(stack)==0 else stack[-1] # n用来标记没有合法右端点
            stack.append(i)
        
        res = 0
        for i in range(n):
            if L[i] != -1 and R[i] != n: # 两端点都有值，就记录答案
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,5,3,1,4]
    print(s.bowlSubarrays(nums))
