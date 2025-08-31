from typing import List

maxNum = 100001
factors = [[] for _ in range(maxNum)]
for i in range(1, maxNum):
    for j in range(i, maxNum, i):
        factors[j].append(i)

class Solution:
    def minDifference(self, n: int, k: int) -> List[int]:
        # 可以求出所有的因数分解方法，然后对于每一种因数分解方法，求出最大值和最小值的差值最小的那一个，即可作为答案返回
        # 在求所有因数分解方法的时候，我们可以用dfs的方式，首先传入一个n，然后对于n的所有因数，都将n除以这个因数，然后将这次使用的因数加入一个列表中，并将除后的数继续传入dfs函数继续进行同样的分解方式，一直到累计的因数个数变成了k，同时此时传入的数字也被除成了1，就说明这个因数分解方式是可行的，因此就可以计算因数列表中的最大值与最小值之差，同时记录答案了
        d = float("inf")
        res = []
        fact = [0]
        def dfs(v):
            if len(fact) == k+1:
                curD = fact[-1]-fact[1] # 在计算过程中保持因数列表中的元素始终是非单减，这样就方便计算差值了
                nonlocal d, res
                if curD < d and v == 1: # 因数分解方式符合条件，同时差值小于之前记录的
                    d = curD
                    res = fact[1:]
                return
            for i in range(len(factors[v])-1, -1, -1):
                if factors[v][i] >= fact[-1]: # 保持非单减顺序
                    fact.append(factors[v][i])
                    dfs(v//factors[v][i])
                    fact.pop(-1)
        dfs(n)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 100
    k = 2
    print(s.minDifference(n, k))
