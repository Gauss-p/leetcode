from typing import List
from sortedcontainers import SortedList

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        # 为了快速找到最左侧元素和最小的相邻元素对，我们可以将所有的相邻元素对(i, i+1)存储为(nums[i]+nums[i+1], i)，即第一个数字表示数对和，第二个数字表示数对中左侧数字位置。然后存入一个有序列表stPairs中，这样，位于列表第0个位置的数对就代表的是最左侧元素和最小的相邻元素对的信息
        # 接下来考虑，当找到一个元素对信息元组(s, i)时接下来应如何维护stPairs数组。根据元组可知，i即为元素对中左侧数字的位置，那么在经过合并后的nums数组中，该数对右侧数字的位置即为数组中索引i下一个位置。这是因为当一个数对被删除之后，如果保留左侧元素的位置，数对右侧元素的位置将被舍弃，最简单的方法是将nums中右侧元素的位置直接弹出，但是这样一来，后面的所有位置都会因此而改变，所以我们可以单纯维护一个「未被舍弃的位置」的有序列表stIndx，这样对于一个左侧位置i，直接在stIndx中二分查找找到i之后的一个索引即为数对的右侧位置j
        # 找到当前处理的位置对(i,j)之后：1.如果i不是stIndx中的第0个索引，记stIndx中i之前的那个位置为before，那么当位置i和j合并之后一定会对before产生影响，即在stPairs中所存储的以before为左侧位置的数对信息会发生改变，因此需要将stPairs中(nums[before]+nums[i], before)删除，替换为(nums[before]+s, before)；2.同理，如果j不是stIndx中的最后一个索引，记j之后的那个位置为after，那么我们需要将(nums[j]+nums[after], j)删除，替换为(s+nums[after], i)
        # 最后，我们需要一直进行以上操作，可是如何结束循环呢？我们可以维护nums中的逆序对的数量，每次我们删除一个位置对的时候，如果该对是逆序对，就将逆序对数量减1，而当我们重新更新一个位置对是，如果该对是逆序对，就应将逆序对的数量加1，一直到逆序对数量变成0为止即可
        n = len(nums)
        stPairs = SortedList(tuple())
        reversedPairs = 0
        for i in range(n-1):
            stPairs.add((nums[i]+nums[i+1], i)) # 所有相邻对
            if nums[i] > nums[i+1]:
                reversedPairs += 1 # 逆序对数量
        stIndx = SortedList(range(n))
        
        res = 0
        while reversedPairs:
            res += 1

            s, i = stPairs.pop(0)
            pos = stIndx.bisect_left(i) # 找出当前应处理的位置对
            j = stIndx[pos+1]
            if nums[i] > nums[j]:
                reversedPairs -= 1
            
            if pos > 0: # i左侧还有位置
                before = stIndx[pos-1]
                if nums[before] > nums[i]:
                    reversedPairs -= 1
                if nums[before] > s:
                    reversedPairs += 1
                stPairs.remove((nums[before]+nums[i], before))
                stPairs.add((nums[before]+s, before))
            
            if pos < len(stIndx)-2: # j右侧还有位置
                after = stIndx[pos+2]
                if nums[j] > nums[after]:
                    reversedPairs -= 1
                if s > nums[after]:
                    reversedPairs += 1
                stPairs.remove((nums[j]+nums[after], j))
                stPairs.add((s+nums[after], i))
            
            nums[i] = s # 保留左侧位置，删除右侧位置
            stIndx.remove(j)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [5,2,3,1]
    print(s.minimumPairRemoval(nums))
