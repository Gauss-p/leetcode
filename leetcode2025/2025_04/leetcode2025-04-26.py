from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        # 我们只要找出minK和maxK在nums分别对应的位置minKPos和maxKPos，就可以首先确定一个小的定界子数组，然后我们再在这个小的子数组前面找到最靠近它的一个不在[minK, maxK]中的元素位置notBelong，这时我们可以发现，只要子数组的右端点保持不动，左端点在(notBelong, minKPos]中任意一个位置，都可以确定该子数组就是我们要求的定界子数组
        # 综上，我们只要找出minKPos,maxKPos,notBelong三个位置，就可以找出一组答案，又因为我们需要子数组的右端点在maxKPos，左端点在(notBelong, minKPos]中，所以我们需要保证notBelong<minKPos，这样，当前可以求出的定界子数组就有minKPos-notBelong个，将其加入总答案即可
        # 但是要注意的是，minKPos有时会比maxKPos大，这时候其实也是符合定界子数组的要求的，因此我们在比较的时候就需要将条件改为notBelong<min(minKPos, maxKPos)，并在计算答案时改为min(minKPos, maxKPos)-notBelong
        myMin = lambda x,y : x if x<y else y
        n = len(nums)
        minKPos = -1 # 最大值对应位置
        maxKPos = -1 # 最小值对应位置
        notBelong = -1 # 不在区间内的元素对应位置
        res = 0
        for i in range(n):
            if nums[i] == minK:
                minKPos = i
            if nums[i] == maxK:
                maxKPos = i
            if nums[i] < minK or nums[i] > maxK:
                notBelong = i
            # 判断条件，统计答案
            if minKPos!=-1 and maxKPos!=-1 and notBelong<myMin(minKPos, maxKPos):
                res += myMin(minKPos, maxKPos)-notBelong
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,5,2,7,5]
    minK = 1
    maxK = 5
    print(s.countSubarrays(nums, minK, maxK))
