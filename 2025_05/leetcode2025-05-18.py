from typing import List
from functools import cache

class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        # 因为一共有三种颜色，所以我们可以用三进制数字中的0，1，2来分别代表红，绿，蓝三色，接下来我们考虑如何解决三进制数字的相邻位置重复问题，为了解决这个问题，我们首先需要在所有候选的三进制数字中循环，这时就需要选择究竟是用一个三进制数字表示一行还是用表示一列，可以发现题目的数据范围中，列的最大长度为5，行的最大长度为1000，因此，论候选三进制数来说，只有选择用一个三进制数字表示一列才能控制合理的候选数字循环量，即3**5-1=242
        # 接下来，如果知道一个三进制数字a，应该如何取出它从右往左数第i位数字呢？参照十进制的取位方式，举个例子，如果一个十进制数字b，我们要取出它的百位也就是从右往左数第2位的数字(从0开始数)，就需要用b//100%10，也就是b//(10**2)%10，换到第3位就需要用b//(10**3)%10，总结一下，如果要取出十进制数字b的从右往左第i位，就需要用b//(10**i)%10。那么回到最开始那个问题，我们就可以采用a//(3**i)%3的方式来取出三进制数a的从右往左第i位
        # 因此，如果要判断同一个三进制数的相邻两位是否相同，就可以用a//(3**(i-1))%3==a//(3**i)%3的方式判断；如果要判断两个三进制数的同一位是否相同，就可以用a//(3**i)%3==b//(3**i)%3的方式判断
        # 我们先用第一种方法找出所有相邻位没有重复数字的三进制数，放入列表valid，再对每一个数字valid[i]进行第二种方法寻找，找出可以与它放在相邻两列的所有三进制数valid[j]，因为可以利用valid中的索引来记录三进制数，所以将这些三进制数字的索引j存入一个列表next_[i]即可
        # 最后定义DFS函数，dfs(i,j)表示在前i列的填充中，第i列填valid[j]的所有情况数，因此dfs(i,j)=sum(dfs(i-1,k))，其中k就是在next_[j]中循环的索引
        # 最终答案就是sum(dfs(n-1,i)),i就是valid中所有索引

        valid = []
        threePows = [3**i for i in range(m)]
        # 选取相邻位没有重复数字的三进制数
        for num in range(3**m):
            flag = True
            for i in range(1,m):
                if num//threePows[i]%3 == num//threePows[i-1]%3:
                    flag = False
                    break
            if flag:
                valid.append(num)

        validLength = len(valid)
        # 选取可以和各个三进制数放在相邻两列的三进制数
        next_ = [[] for _ in range(validLength)]
        for i in range(validLength):
            for j in range(validLength):
                flag = True
                for k in threePows:
                    if valid[i]//k%3 == valid[j]//k%3:
                        flag = False
                        break
                if flag:
                    next_[i].append(j)

        mod_num = 1_000_000_007
        @cache
        # 计算在前i列中第i列填valid[j]时的总方案数,根据定义,边界就是dfs(0,j)=1
        def dfs(i, j):
            if i == 0:
                return 1
            ans = 0
            for k in next_[j]:
                ans = (ans+dfs(i-1, k))%mod_num
            return ans

        # 统计答案
        res = 0
        for i in range(validLength):
            res = (res+dfs(n-1, i))%mod_num
        return res

if __name__ == "__main__":
    s = Solution()
    m, n = 5, 5
    print(s.colorTheGrid(m, n))
