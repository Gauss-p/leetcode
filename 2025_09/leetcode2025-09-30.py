from typing import List

class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        # 如果进行模拟，可以发现最终得到的数字就是nums中各个数字乘上不同的系数相加得到的数字再模除10，因此，我们只需要找到其系数规律即可。通过几次模拟，我们可以发现，当len(nums)=1时，系数为1，当len(nums)=2时，系数为1,1，当len(nums)=3时，系数为1,2,1，当len(nums)=4时，系数为1,3,3,1，当len(nums)=5时，系数为1,4,6,4,1……以此类推，可以发现当长度为n的时候，系数就是(1+x)**n的各项系数
        # 因此可以直接用组合数求出各数字对应的系数。可以发现每一个系数都和上一个系数有关，比如C(n-1, i+1)=C(n-1, i)*(n-1-i)//(i+1)，利用这个式子，就可以直接求出各项系数
        n = len(nums)-1
        res = 0
        cur = 1
        for i in range(len(nums)):
            res += nums[i]*cur
            cur = cur*(n-i)//(i+1)
        return res%10

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4,5]
    print(s.triangularSum(nums))
