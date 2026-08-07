from functools import *
from math import gcd

class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        primes = [2,3,5,7]
        tmp = t
        for i in primes:
            while tmp%i == 0:
                tmp //= i
        if tmp > 1:
            return "-1"

        num = '0'*50+num # 前面加上50位，防止填数字时数位不够用
        n = len(num)
        res = ""
        @cache
        def dfs(indx, curT, isLarge):
            # 当前要填indx位，剩余填的数字之积应当是curT的倍数，并且isLarge表示之前填的数字中是否有比nums对应位置大的
            nonlocal res
            if indx == n:
                # 如果curT已经是1，说明前面填的所有数字之积为t的倍数，返回True，否则返回False
                return True if curT==1 else False
            low = 0 # 如果indx<50，说明处在添加的50位0中，最小数字可以填0
            high = 9
            if indx >= 50:
                # 只要大于等于50，进入了真正给出的num中时，才依据isLarge确定当前位置可以填的最小数字
                low = 1 if isLarge else int(num[indx])
                low = max(low, 1) # 防止nums中该位置是0

            for i in range(low, high+1):
                newT = curT if i == 0 else curT//gcd(curT, i) # 如果当前位置填i，那么剩下的所有数字之积就不需要是t的倍数，只需是curT//gcd(curT,i)的倍数，再乘上i就是curT的倍数了
                nxt = dfs(indx+1, newT, isLarge|(i > int(num[indx])))
                if not nxt:
                    continue
                res = str(i)+res # 由于题目要最小数字，故只要找到一个满足条件的即可确定当前位置，退出循环
                return True
            return False

        dfs(0, t, False)
        dfs.cache_clear()
        while res[0] == '0':
            res = res[1:]
        return res

if __name__ == "__main__":
    s = Solution()
    num = "1234"
    t = 256
    print(s.smallestNumber(num, t))
