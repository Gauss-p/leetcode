from typing import List
from heapq import *

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        # 贪心地想，如果一些区间的左端点相同，那么为了节省剩下的区间，肯定是右端点越后面越好，所以我们首先将queries数组按照左端点排序，然后用优先级队列存储右端点即可快速找出当前的最佳区间
        # 定义一个数组minus，其中minus[i]就是nums[i]需要减掉的数字，因此如果选择一个区间[l,r]，则需将minus[l:r]中的所有数字都加上1，这时nums能变成0数组的条件就是对于所有i都有minus[i]>=nums[i]。
        # 为了快速将一整个区间加1，可以用差分数组的方法。定义差分数组sub，其中sub[i] = minus[i]-minus[i-1]，因此在循环中为了还原minus[i]，则需用一个数不断累加sub[i]，我们称这个数字为op，所以对于每一次循环，都只需要将op变得大于等于nums[i]
        # 同时我们用一个优先级队列q来存储左端点小于等于i的所有区间的右端点值。为了实现这一点，我们需要在每一次循环的时候将所有左端点等于i的区间对应的右端点加入q，这样，之前加入的所有区间其实都可以保证左端点小于i
        # 在获取到当前位置已经减去的值和所有的右端点后，我们就需要不断选择最大的右端点进行操作(需要注意的是，每一次操作的前提是该右端点大于等于i，即该右端点对应的区间是包含i的)，每一次操作之后就可以确定当前位置又多减掉一个1，那么我们将op加上1，一直到op等于nums[i]或没有剩余区间为止，退出while循环。因此在退出循环后有两种情况，第一种是op=nums[i]，第二种是op<nums[i]但len(q)=0，所以对于第二种情况就直接返回-1，因为没有多余的包括i的区间了
        # 最终的答案就是q中剩余右端点的个数，因为这些区间是不需要用的
        queries.sort(key = lambda x:x[0]) # 排序
        q = [] # 优先级队列，存储区间右端点
        sub = [0]*(len(nums)+1) # minus的差分数组
        op = 0 # 对应minus[i]
        j = 0 # 在queries中的下标
        for i in range(len(nums)):
            cur = nums[i]
            op += sub[i] # 还原minus[i]
            while j<len(queries) and queries[j][0]==i:
                heappush(q, -queries[j][1]) # 更新左端点等于i的区间右端点
                j += 1

            while op<cur and len(q)>0 and -q[0]>=i:
                sub[i] += 1 # 这里由于不知道该右端点对应的左端点是哪里，并且之后不会用到sub[i]，所以其实可以不需要这一句
                sub[-heappop(q)+1] -= 1
                op += 1 # 每次操作过后都相当于nums[i]多减了1
            if op<cur:
                # 无剩余包含i的区间
                return -1
        return len(q)

if __name__ == "__main__":
    s = Solution()
    nums = [2,0,2]
    queries = [[0,2],[0,2],[1,1]]
    print(s.maxRemoval(nums, queries))
