from typing import List

modNum = 1_000_000_007
maxNum = 100001
pow2 = [1]*maxNum
for i in range(1, maxNum):
    pow2[i] = (pow2[i-1]<<1)%modNum # 提前预处理所有的2的幂

class Solution:
    def countEffective(self, nums: List[int]) -> int:
        # 如果直接计算所有的满足 或值小于nums的总或值 这个条件的子序列，太过繁琐，同时会导致时间和空间开销过大以至于超出时间或内存限制。因此，正难则反，我们可以选择计算或值正好等于nums的总或值的子序列个数，最后用nums的子序列总个数减去这个数字即可得到或值小于nums总或值的子序列总个数，即所求答案
        # 为了叙述方便，我们称nums的总或值为orTot
        # 可以采用动态规划的思路，定义f[i]表示nums中「是i的二进制子集」的数字个数，因此在初始化f中各个位置的值的时候就将nums中的各个数字对应的位置加1即可。那么接下来问题就变成了：如何计算所有可能出现的或值对应的子序列总个数？首先，我们需要判断那些或值可能出现，可以发现，只有那些二进制中是1的位恰好是orTot的子集的数字，在nums中才能找到在那一位上是1的数字，因此我们可以按位循环，从最低位循环到最高位，当且仅orTot在当循环到的位置上是1的时候我们才进行进一步处理；
        # 其次，根据对f数组的定义，我们需要对于所有可能的值s，在f[s]中统计所有「值是s的二进制子集」的数字的个数，也就是对于s中的每一个是1的二进制位bit，将s中的bit位变成0得到一个更小的或值newS，把f[newS]加在f[s]上即可。但由于我们选择的是按照二进制位从低到高依次循环，因此可以将上面的过程反一下，对于每一个二进制位i，我们更新所有在第i位上是1的值s在f数组中对应的数量，也同样可以实现上述效果
        # 当我们对于所有的位置都进行完上述操作后，我们就将所有可能的值s对应的「在nums中数字是s的二进制子集」的个数统计出来了

        # 根据f数组定义可以发现：如果要计算nums中或值是某个值i的二进制子集的总个数，我们在被记录的所有数字中任选多个均可以满足条件，因此真正的总个数应为：pow(2, f[orTot])
        # 接下来计算答案。按照原思路，我们需要计算出所有或值正好等于orTot的子序列个数，但是根据对f数组的定义，我们并不能直接将pow(2, f[orTot])作为答案，而是需要将orTot二进制的子集减去才可以，也就是说，对于orTot的二进制子集对应的任意一个数字curOr，如果curOr和orTot两者相差的1的数位是1，则需要将pow(2, f[curOr])减去；但是这样一来，所有curOr的二进制子集对应的数又被多减了一次，因此对于那些和orTot两者相差的1的数位是2的curOr，我们又需要加上pow(2, f[curOr])...以此类推，可以发现，如果curOr和orTot的二进制中相差的1的数位是奇数，我们需要减去pow(2, f[curOr])，否则需要加上pow(2, f[curOr])。而这正是韦恩图的计算方式，即容斥原理
        # 最后用2**(len(nums))即nums中所有子序列数量，减去或值正好等于orTot的子序列个数即可得到答案
        orTot = 0 # 计算nums总或值
        for x in nums:
            orTot |= x
        w = orTot.bit_length()

        f = [0]*(1<<w)
        for x in nums:
            f[x] += 1 # 初始化f中所有值

        for i in range(w):
            bit = 1<<i
            if orTot & bit == 0: # 去除不可能的值
                continue

            s = 0
            while s<=orTot:
                s |= bit # 只循环bit位是1的可能的值s，每次或bit是为了保证s在bit位上始终为1
                f[s] += f[s^bit]
                s += 1
        
        # for i in range(w):
        #     if (orTot>>i)&1==0:
        #         continue

        #     for s in range(1<<w):
        #         if (s>>i)&1:
        #             f[s] += f[s^(1<<i)]
            
        subSet_equals_orTot = 0 # 或值正好等于orTot的子序列总个数
        curOr = orTot
        while True:
            p = pow2[f[curOr]] # 或值是curOr二进制子集的子序列总个数
            if (curOr^orTot).bit_count() & 1:
                subSet_equals_orTot -= p
            else:
                subSet_equals_orTot += p
            
            if curOr == 0:
                break

            curOr = (curOr-1)&orTot
        
        res = (pow2[len(nums)]-subSet_equals_orTot)%modNum
        return res
        


        # modNum = 1_000_000_007
        # n = len(nums)
        # tot = 0
        # for i in nums:
        #     tot |= i
        # @cache
        # def dfs(indx, val):
        #     if val == tot:
        #         return pow(2, n-indx, modNum)
        #     if indx == n:
        #         return 0
        #     ans = 0
        #     ans = (ans+dfs(indx+1, val))%modNum
        #     ans = (ans+dfs(indx+1, val|nums[indx]))%modNum
        #     return ans
        # return (pow(2, n, modNum)-dfs(0, 0))%modNum

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.countEffective(nums))
