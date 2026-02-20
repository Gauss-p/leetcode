from typing import List
from collections import Counter

MOD_NUM = 1_000_000_007
def mat_mul(a, b):
    # 矩阵乘法
    m, n, p = len(a), len(a[0]), len(b[0])
    ans = [[0]*p for _ in range(m)]
    for i in range(m):
        for j in range(p):
            for k in range(n):
                ans[i][j] = (ans[i][j]+a[i][k]*b[k][j])%MOD_NUM
    return ans

def quick_pow1(mat, n, f0):
    # 快速幂
    res = f0
    while n>0:
        if n&1:
            res = mat_mul(mat, res)
        mat = mat_mul(mat, mat)
        n >>= 1
    return res

def quick_pow2(mat, n, f0):
    # 为适应第二种方法，改变乘法顺序
    res = f0
    while n>0:
        if n&1:
            res = mat_mul(res, mat)
        mat = mat_mul(mat, mat)
        n >>= 1
    return res

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        # 首先考虑动态规划，定义f[i][j]表示字母j替换i次后的长度，如果考虑状态转移方程，那么对于第一个示例中的所有字符，因为如果我们要求'a'替换t次的长度，就需要知道'b'替换t-1次的长度，以此类推，可以分析得到以下递推关系式：
        # f[i][0]=f[i−1][1]
        # f[i][1]=f[i−1][2]
        # f[i][2]=f[i−1][3]
        # ⋮
        # f[i][23]=f[i−1][24]
        # f[i][24]=f[i−1][25]
        # f[i][25]=f[i−1][0]+f[i−1][1]
        # 通过观察，我们可以发现如果用矩阵来总结上面的公式会显得较为简单，等式左边是1×26的单列矩阵，从上到下依次为f[i][0],f[i][1],...,f[i][25]，等式右边则为两个矩阵相乘，第一个矩阵是26×26的矩阵，每一行都由0和1构成，其中第i行中的第j个元素为1表示字母表中第i个字符可以通过一次变换变成字母表中第j个字符，因此根据题意，我们可以依据数组nums来生成这个矩阵。等式右边的第二个矩阵也是一个1×26的单列矩阵，从上到下依次为f[i-1][0],f[i-1][1],...,f[i-1][25]，这样，经过矩阵乘法就可以得到上面的所有递推式，大致如下：
        #  __    __     __       __     __      __
        # |f[i][0] |   |0 1 0 ... 0|   |f[i-1][0] |
        # |f[i][1] |   |0 0 1 ... 0|   |f[i-1][1] |
        # |...     | = |...........| × |...       |
        # |f[i][25]|   |1 1 0 ... 0|   |f[i-1][25]|
        #  --    --     --       --     --      --
        # 为了简单，我们称为将上面从左到右三个矩阵依次称为fi,M,fi-1
        # 以此类推，我们可以得到fi = M*M*M*...*M*f0，而f0我们假设为所有字符都出现一次，即f0中所有元素都是1，所以我们只需要求出M**t即可，这个我们可以自己写一个函数来计算两个矩阵相乘，并用快速幂的方式计算M**t
        # 所以最终我们可以得到ft = (M**t)*f0，那么ft[i]就代表字母表中第i个元素替换t次后的长度，将它与该字符在原字符串中出现的次数相乘并累加即可得到答案
        f0 = [[1] for _ in range(26)]

        mat = [[0]*26 for _ in range(26)]
        # 计算中间的方阵
        for i in range(26):
            for j in range(i+1, i+nums[i]+1):
                mat[i][j%26] = 1

        resMat = quick_pow1(mat, t, f0) # 快速幂计算答案
        res = 0
        cnt = Counter(s)
        for c, v in cnt.items():
            # 累加答案
            res = (res+v*resMat[ord(c)-ord('a')][0])%MOD_NUM
        return res

        # ====================================================================
        # 也许我们会想到为什么不能用原字符串中的各字符数量来充当f0中的值呢？这是可以的，但是我们需要将乘法的顺序和f0的组成方式改变一下，将f0变为26×1的矩阵，之后用f0*M*...*M，即乘以t个M矩阵，最后将f0中所有元素相加即可得到原来的效果
        # f0 = [[0]*26]
        
        # for c in s:
        #     f0[0][ord(c)-ord('a')] += 1

        # mat = [[0]*26 for _ in range(26)]
        # for i in range(26):
        #     for j in range(i+1, i+nums[i]+1):
        #         mat[i][j%26] = 1

        # resMat = quick_pow2(mat, t, f0)
        # res = 0
        # for i in resMat[0]:
        #     res = (res+i)%MOD_NUM
        # return res

if __name__ == "__main__":
    sl = Solution()
    s = "abcyy"
    t = 2
    nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]
    print(sl.lengthAfterTransformations(s,t,nums))
