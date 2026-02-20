from typing import List
from collections import defaultdict

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        # 更简洁的方法写在c++中，这里是我自研的一个方法
        # 首先，读题可知，我们要求的是以每一个位置为起始位置的子数组中，拥有最大按位或值且最短的子数组长度，因此我们先考虑按位或值最大，如果知道了从一个位置开始的最大可能按位或值，我们只需从当前位置开始向后遍历，只要当前的或值累积到最大值就可以直接记录答案了。
        # 利用或运算的单调递增性质，我们可以知道从任意一个位置开始，想要得到最大按位或值，最好直接将子数组的右端点取到整个数组的末尾，也就是对于任意一个位置i，以它开始的子数组的最大按位或值就是：or(nums[i:])，因此在实现的时候，我们可以倒序遍历，从末尾开始向前累计按位或值，就可以得到以每一个位置为起始位置的最大可能按位或值
        # 接下来，我们可以考虑滑动窗口，自动遍历左端点，手动滑动右端点，一直到当前窗口内的按位或值能够达到左端点对应的最大可能按位或值为止，最后我们记录左右端点的距离，并保存至左端点对应的答案处即可
        # 注意，按位或在滑动窗口中无法用前缀和类似的方式预处理，因此我们需要维护一个字典，用来保存每一个二进制位上1出现的个数，并用两个函数getVal和addVal分别实现得到字典里面对应的十进制值以及加入或删除一个十进制数字
        n = len(nums)
        maxOr = [0]*n
        maxOr[n-1] = nums[n-1] # 得到每一个位置为开始的最大可能按位或值
        for i in range(n-2, -1, -1):
            maxOr[i] = maxOr[i+1]|nums[i]
        
        def getVal(cnt):
            # 得到当前字典中存储的二进制所对应的十进制值
            ans = 0
            for k, v in cnt.items():
                ans += pow(2, k)*(v>0)
            return ans
        
        def addVal(x, op):
            # 在字典中加入一个十进制数字
            pos = 0
            while x>0:
                if x&1:
                    cnt[pos] += op
                    if cnt[pos] == 0:
                        cnt.pop(pos)
                x >>= 1
                pos += 1

        res = [0]*n
        r = 0
        cnt = defaultdict(int)
        for l in range(n):
            if maxOr[l] == 0:
                # 这里如果maxOr[l]=0，就说明nums[l:]中的所有值都是0，因此直接记录答案即可
                res[l] = 1
                continue
            while r<n and getVal(cnt)<maxOr[l]:
                # 一直循环到窗口内的按位或值等于最大值才退出
                addVal(nums[r], 1)
                r += 1
            res[l] = r-l
            addVal(nums[l], -1) # 删除窗口内的左端点
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,0,2,1,3]
    print(s.smallestSubarrays(nums))
