from typing import List
from collections import deque

class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        # 首先分析，一个子数组变成非递减子数组的最小操作次数是多少？由于要将它变成非递减的，那么就说明对于任意一个不是最左端的位置i，都需要操作直到它满足nums[i]>=max(nums[:i])为止，即，如果nums[i]<max(nums[:i])，就操作到nums[i]=max(nums[:i])，否则就不操作。
        # 用滑动窗口的思路，从右往左遍历整个数组，对于一个窗口[l,r]，假如已经知道它对应的操作总次数cnt，那么需要考虑以下两种操作之后，窗口对应的操作总次数变化：
        #   1.将窗口左端向左滑一个位置，即将nums[l-1]加入窗口当中。根据已有信息可知，在cnt次操作之后，nums[l...r]这个子数组可以变成一个非递减的子数组，那么当在左侧加入一个新元素之后，唯一可能对总操作次数产生影响的情况就是nums[l-1]>nums[l]，即在子数组nums[l...r]的某一个前缀中，每个位置对应的前缀最大值都变大成了nums[l-1]，此时就需要遍历该子数组开头的所有值小于nums[l-1]的位置，并将它们加至nums[l-1]，将需要多加的次数加到cnt中。
        #   2.将窗口右端向左滑一个位置，即将nums[r]移出窗口。这就比较简单了，只需要知道它需要加到多少以及它原本是多少，直接相减即可得到cnt需要减少了量了。
        # 注意到两个操作都牵扯到某个位置究竟已经被加到了多少，因此可以用一个双端队列来存储这些信息。注意到当经过最少次数的操作后将一个数组变成非递减数组后，它一定是由多个重复元素的段拼接而成的，因此在这个队列中的元素均为(value, length)形式的二元组，在更改窗口中内容的时候只需一段一段处理即可。
        n = len(nums)
        r = n-1
        cost = 0
        res = 0
        dq = deque() # 存储每一段数据
        for l in range(n-1, -1, -1):
            x = nums[l]
            cnt = 1
            while len(dq) and dq[-1][0]<=x:
                # 如果原有窗口中左侧段的值小于等于x，说明它们需要继续增加至x
                cur, tot = dq.pop()
                cost += (x-cur)*tot # 总共有tot个数字要从cur加到x
                cnt += tot # 窗口左侧值为x的段总长度
            dq.append((x, cnt)) # 更新窗口内数据
            
            while cost>k:
                cur, tot = dq.popleft()
                cost -= (cur-nums[r]) # 最右侧段对应的最终加到的值减去右端点的原值即可得到右端点位置累加的总次数
                if tot > 1:
                    dq.appendleft((cur, tot-1)) # 将减去一个元素的段继续加入dq中
                r -= 1
            
            res += (r-l+1) # 累加答案
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [6, 3, 1, 2, 4, 4]
    k = 7
    print(s.countNonDecreasingSubarrays(nums, k))
