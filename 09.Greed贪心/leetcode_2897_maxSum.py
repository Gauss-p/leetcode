from typing import List

class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        # 分析操作的实质，在经过一次变化后，原先两个数字相同的二进制位在操作后均不会改变，而对于两个数字中不同的二进制位，AND操作出的数字就是0，OR操作出的数字就是1，也就意味着，无论怎样操作，二进制中单个位置上的1的总数是不会变的，只是会变到不同的数字中而已，因此可以对于每一个二进制位都统计出：nums中所有数字中有多少个数字在这个位置上有1，这样，每次只需将仍然剩余有1可以选的位置都置为1，即可得到当前能够通过操作取得的最大数字，相同的操作执行k次即能够得到最大的k个数字。需要注意的是，在一个位置上选了一个1后，需要将统计数组中这个位置上1出现的次数减1，保证数组中同一二进制位的1的个数保持不变。
        modNum = 1_000_000_007
        m = max(nums).bit_length()
        cnt = [0]*m
        for i in nums:
            for pos in range(m):
                if (i>>pos)&1:
                    cnt[pos] += 1 # 统计各个二进制位在nums所有数字中是1的数量
        
        res = 0
        for i in range(k):
            cur = 0
            for pos in range(m):
                if cnt[pos]:
                    cur |= (1<<pos) # 只要有可选的1就将该位置置为1
                    cnt[pos] -= 1
            res += cur*cur # 取得了当前最大值，累计答案
        return res%modNum

if __name__ == "__main__":
    s = Solution()
    nums = [2,6,5,8]
    k = 2
    print(s.maxSum(nums, k))
