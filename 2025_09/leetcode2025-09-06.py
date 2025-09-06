from typing import List
from math import log

class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        # 定义函数calc(x)用来计算[1,x]中每一个数需要变成0的操作次数总和，那么我们就可以用前缀和的方式求出每一个查询对应的所有数字需要的总操作次数，那么此时我们只需要每次进行两个操作，也就是将总操作次数除以2向上取整即可得到对应的答案了
        # 在计算calc(x)的时候，我们可以用4的幂不断累加，其中我们知道[4**p, 4**(p+1))中的所有数字都需要操作(p+1)次，因此对于4**(p+1)还没有超过给出的x的时候，我们可以直接用(p+1)*(4**(p+1)-4**p)的方式来计算答案并累加，否则，我们就需要用(p+1)*(x-(4**p)+1)的方式计算最后剩余的一些数字的答案
        # 那么循环所有可能的p，分别进行计算即可
        def calc(x):
            if x == 0:
                return 0
            ans = 0
            powNum = int(log(x, 4))
            curNum = 1 # 对应的4**p
            for p in range(powNum+1):
                if p<powNum:
                    # 4**(p+1)<=x
                    ans += (p+1)*(curNum*4-curNum)
                else:
                    # 4**p<=x<=4**(p+1)
                    ans += (p+1)*(x-curNum+1)
                curNum *= 4
            return ans
        
        res = 0
        for l,r in queries:
            res += (calc(r)-calc(l-1)+1)//2 # 向上取整
        return res

if __name__ == "__main__":
    s = Solution()
    queries = [[1,2],[2,4]]
    print(s.minOperations(queries))
