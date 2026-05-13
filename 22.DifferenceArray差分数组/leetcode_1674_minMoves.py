from typing import List

class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        # 实际上本题目要求的就是：找到一个目标值target，使得nums中每一对下标对(i,n-i-1)都满足nums[i]+nums[n-i-1]=target所需要进行操作次数最小化。因此可以对于所有可能的target值，都计算出其对应所需要的操作次数
        # 对于一个下标对(i,n-i-1)，假设nums[i]=a, nums[n-i-1]=b，考虑不同的操作次数能够得到的nums[i]+nums[n-i-1]值的区间：
        # 1.如果不进行操作，那么nums[i]+nums[n-i-1]的值只能是a+b;
        # 2.如果进行一次操作，那么最小可以达到的值就是1+min(a,b)，最大可以达到的值就是limit+max(a,b)(注意这里是因为limit已经保证大于等于nums中所有数字)
        # 3.如果进行两次操作，那么最小可以达到的就是2(两个都变成1)，最大可以达到的值就是2*limit(两个都变成limit)
        # 如果定义res[i]表示当target=i时所需要的操作次数，那么对于新计算的一组(a,b)，可以发现res[a+b]不需要改变，且res[1+min(a,b):limit+max(a,b)+1]中的所有值都需要加1，且res[2:limit*2+1]中的所有值都需要加2，注意到都是对区间进行同加同减，因此可以用差分数组来实现高效的区间同加同减操作
        n = len(nums)
        diff = [0]*(2*limit+2)
        for i in range(n//2):
            a, b = nums[i], nums[n-i-1]

            # 为了计算方便，先计算最大的区间，对应都加2，然后对于次大的区间，都减1，最后对于单个元素的区间再减1，即可实现对所有情况的完整模拟
            l, r = 2, 2*limit
            diff[l] += 2
            diff[r+1] -= 2

            l, r = 1+min(a,b), limit+max(a,b)
            diff[l] += -1
            diff[r+1] -= -1

            l, r = a+b, a+b
            diff[l] += -1
            diff[r+1] -= -1
        
        res = n
        cur = 0
        # 还原res数组，求最小值，注意不能循环到最后一个数，同时由于计算中最小的索引是2，需要从2开始计算
        for i in diff[2:2*limit+1]:
            cur += i
            res = min(res, cur)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,4,3]
    limit = 4
    print(s.minMoves(nums, limit))
