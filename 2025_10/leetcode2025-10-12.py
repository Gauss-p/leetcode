from typing import List
from functools import cache

# 预处理各数字的阶乘和阶乘的逆元
MOD_NUM = 1_000_000_007
MAX_NUM = 31
fact = [1]*31
for i in range(2, MAX_NUM):
    fact[i] = (fact[i-1]*i)%MOD_NUM

inv = [0]*31
inv[-1] = pow(fact[-1], MOD_NUM-2, MOD_NUM)
for i in range(MAX_NUM-1, 0, -1):
    inv[i-1] = (inv[i]*i)%MOD_NUM

class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        # 首先分析题目，我们需要找的是多个数组的和，而这些数组满足以下条件：以2为底，每一个数分别为指数求出其值，所有的2的幂相加之后，得到的和的二进制中有k个1.而我们需要计算的，则是对于每一个可能的数组，求出数组中每一个数字分别对应的nums中的值之积，然后将所有的积再次求和，这是我们最终的目标
        # 首先我们需要将问题简化，考虑如果选择了j个索引i，那么它们对答案的贡献是多少？举个例子，如果n=2, m=5，此时选择了2个下标0和3个下标1，那么它们所组成的答案就是(nums[0])**2 * (nums[1])**3，但是还需要乘以2个下标0和3个下标1的所有排列情况，根据组合数学的去重原则，我们需要将全排列数除以各个数字重复次数的阶乘，因此还需要乘以(5!/(2!*3!))，也就是说，总的答案应当写为：(nums[0])**2*(nums[1])**3 * (5!/(2!*3!))，将顺序改变一下，即可得到：((nums[0]**2)/2!)*((nums[1]**3)/3!)*5!。因此可以得出：如果选择了j个索引i，那么对答案的贡献就是(nums[i]**j)/j!
        # 处理完乘法，我们还需要处理加法的问题。由于我们打算采用dfs的方式构建目标数组，所以为了判断当前数组是否符合要求，我们还需要求出对于目标数组求和后是1的二进制位数量，但是如果直接求，总数量太大，而且不方便记忆化搜索，因此可以这样考虑：因为我们在递归的时候传入的索引i是单调递增的，也就是说对于一次计算而言，无论选择多少个i，对于总和的最小的i个二进制位是没有任何影响的，因此我们在传入的时候只传总和右移i位的数字即可
        # 接下来我们可以考虑构造目标数组，用dfs的方式构建，其中传入四个参数i,leftM,x,leftK，其中i表示现在需要选择的下标是i，leftM表示还需要选择多少个数字，x表示总和右移i位之后的数字，leftK表示还需要选择多少个1。那么将j从0到leftM进行遍历，表示选择j个索引i，那么考虑下一次传入的数字变化：首先索引变为i+1，leftM由于选掉了j个而变成leftM-j，x只需在它最后加上j，即可表示多加了j个1<<i，而因为继续传入的时候需要再次右移一位，所以传入值就变为了(x+j)//2，至于leftK的变化，则取决于x+j之后的最后一位是否是1，如果是就需要将leftK减1，否则不变
        # 最后考虑递归基，可以发现，如果当我们已经处理完最后一个索引，或leftM=0，leftK=0时，我们都无法继续选择数字，这时候就直接返回答案即可，而答案就是：当i=n且leftK=0时，答案为1，否则答案为0
        n = len(nums)
        powV = [[1]*(m+1) for _ in range(n)]
        for i in range(n):
            for j in range(1, m+1):
                powV[i][j] = (powV[i][j-1]*nums[i])%MOD_NUM # 预处理每一个数字的幂次
        
        @cache
        def dfs(i, leftM, x, leftK):
            cnt = x.bit_count()
            if i==n or leftM==0 or leftK==0:
                return 1 if cnt==leftK and leftM==0 else 0 # 递归基
            
            ans = 0
            for j in range(leftM+1):
                cur = dfs(i+1, leftM-j, (x+j)//2, leftK-((x+j)%2))
                ans = (ans+cur*powV[i][j]*inv[j])%MOD_NUM # 加上对答案的贡献
            return ans%MOD_NUM

        return dfs(0, m, 0, k)*fact[m]%MOD_NUM # 最后还需要乘以总排列数，因为计算时是将其提取出来计算的

if __name__ == "__main__":
    s = Solution()
    m, k = 5, 5
    nums = [1,10,100,10000,1000000]
    print(s.magicalSum(m, k, nums))
