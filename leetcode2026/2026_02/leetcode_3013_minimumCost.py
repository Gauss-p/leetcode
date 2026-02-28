from typing import List
from sortedcontainers import SortedList

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        # 分析题目，如果要分成多个子数组，那么第一个子数组的‘代价’一定是nums[0]，无论怎么分，nums[0]是一定要被计入答案中的。接下来考虑剩下的k-1个子数组，根据题目的要求，我们需要让「第二个子数组与第k个子数组中第一个元素的下标距离不超过dist」，其实就相当于要令这k-1个子数组的开头元素分布在一个长度为dist+1的区间内，因此可以想到用滑动窗口的方式保持一个长度为dist+1的区间，每次在这个区间里划分数组即可
        # 如果单纯暴力遍历所有划分数组的方式，求代价的最小值，复杂度太高，一定会超时，因此我们需要考虑如何在一个区间内快速找到总代价最小的划分方式。可以发现，一个数组的代价就是这个数组的第一个元素，和顺序没有任何关系，因此如果要让划分出来的k-1个数组代价和最小，其实就是在这个区间中选最小的k-1个数字，求和即可
        # 因此我们可以维护一个有序列表，记录这个长度为dist+1的区间内的所有元素，每次找这个有序列表的前k-1个数字，求和即可得到当前情况下的最小代价，但是单纯利用有序列表每次求和太慢，因此可以只维护前k-1个数字的和。
        # 如何维护这个和？当加入一个数字的时候，如果在列表中插入后这个数字处在前k-1个数字的位置，那么就在总和tot中加入这个数字，并删除掉被这个数字顶出前k-1个数字范围的那个数字，也就是在插入后索引变为k-1的那个数字
        # 当删除一个数字的时候，先判断它是否处在前k-1个数字范围内，如果在，就在总和tot中删除它，之后，当且仅当有序列表的长度大于k-1时，我们将当前位于位置k-1的数字加入tot中，因为在删除前面一个数字之后，它就进入了前k-1个数字的范围。可是如果长度小于等于k-1，就不需要继续维护，因为删除一个元素之后列表本身已经不足k-1个了
        # 最后，每次都记录tot的最小值，最终加上nums[0]即为总代价
        n = len(nums)
        stl = SortedList()
        tot = 0
        res0 = nums[0]
        res1 = float("inf")
        for i in range(1, n):
            stl.add(nums[i])
            if len(stl) <= k-1:
                tot += nums[i]
            else:
                indx = stl.bisect_left(nums[i])
                if indx < k-1: # 更新前k个数字
                    tot -= stl[k-1]
                    tot += nums[i]
                    
            if i<=dist:
                continue
                
            res1 = min(res1, tot)
            indx = stl.bisect_left(nums[i-dist])
            if indx < k-1:
                tot -= nums[i-dist] # 删除左端点数字
                if len(stl) > k-1:
                    tot += stl[k-1]
            stl.pop(indx)
            
        return res0+res1

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,2,6,4,2]
    k = 3
    dist = 3
    print(s.minimumCost(nums, k, dist))
