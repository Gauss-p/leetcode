from functools import *

# 解决本题的思路很简单，实际上就是模拟计算每个子串变成半回文串的代价，最后用dfs的方式计算将整个字符串划分成k个部分的最小代价即可。因此总共代码分成两部分：1.计算每个子串变成半回文串的最小代价；2.计算整个字符串划分成k个部分的最小代价
# 1：为了方便叙述，称当前计算的子字符串为s_sub。那么根据题意，首先需要找到len(s_sub)的所有因数，之后，对于每一个因数d，题目实际上进行的是下面的操作：将s_sub按照长度d分成len(s_sub)//d个部分，然后将每一部分的第0个字符取出来，按顺序排成一个字符串，再将每一部分的第1个字符取出来，按顺序排成一个字符串……以此类推，总共组出d个字符串，然后对于每一个新组出的字符串，都计算一下将它变成回文串的修改次数，求出修改次数的总和即可得到按照长度d划分的修改次数，按照同样的方式计算出所有因数对应的修改次数，求它们中间的最小值，即可得到s_sub修改称半回文串的最少修改次数。最后用双重循环传入所有子串进行计算即可得到每个子串变成半回文串的最小代价。记将s[i...j]变成半回文串的最小代价为totCost[i][j]；
# 2：定义dfs(i,j)表示将s[0...j]划分成i+1段时的最少修改次数，那么最后一段一定是以j结尾的，需要做的只是对于所有可能的左端点遍历并计算对应的代价，求出最小值即可。根据题目可知，一个半回文串的长度至少为2，因此如果左端点是l，那么为了给左边i个段留出足够字符，它一定要满足l∈[i*2,j-1]，且此时的代价就应该是dfs(i-1, l-1)+totCost[l][j]。遍历所有可能的l，求出最小值即可。需要注意的是，如果i=0，说明当前对应的就是最左边的一段，直接返回totCost[0][j]即可。

maxNum = 201
factors = [[1] for _ in range(maxNum)] # 预处理每个数的所有因数
for i in range(2, maxNum):
    for j in range(i*2, maxNum, i):
        factors[j].append(i)

class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        def calcCost(l, r): # 计算s[l...r]对应的代价
            cur = s[l:r+1]
            cost = n
            length = r-l+1
            for d in factors[length]:
                cnt = 0
                for i in range(d):
                    i1, i2 = l+i, r-d+i+1
                    # i1,i2初始值分别是最前面一段和最后面一段中的第i个元素
                    while i1<i2:
                        cnt += (s[i1] != s[i2])
                        i1 += d # 跳到下一段的第i个元素
                        i2 -= d # 跳到上一段的第i个元素
                cost = min(cost, cnt)
            return cost
            
        totCost = [[0]*n for _ in range(n)]
        for i in range(n-1):
            for j in range(i+1, n):
                totCost[i][j] = calcCost(i, j)
        
        @cache
        def dfs(group, indx):
            if group == 0:
                return totCost[0][indx]
            ans = 10**18
            for i in range(group*2, indx):
                ans = min(ans, dfs(group-1, i-1)+totCost[i][indx])
            return ans
        return dfs(k-1, n-1)

if __name__ == "__main__":
    sl = Solution()
    s = "abcac"
    k = 2
    print(sl.minimumChanges(s, k))
