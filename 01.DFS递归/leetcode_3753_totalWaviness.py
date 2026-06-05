from functools import *

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        # 定义dfs函数用来计算[0,num]范围内的总波动值，那么可以利用前缀和的思想，求出[0,num2]范围内的总波动值，减去[0,num1-1]范围内的总波动值，即可得到答案
        # 如果确定了indx位置填写的数字，那么根据第indx-2位的数字就可以确定第indx-1位是否可以计入波动值中，因此在dfs函数中需要保存前两位的数字。接下来，为了确定当前位置能够填写的数字范围，还需要知道之前所有位置上所填写的数字和最大数字限制中对应位置的大小情况，只要有一个数字小于最大数字对应位置的数字，最大就可以填写9，否则最大只能填写最大数字对应位置的数
        # 同时，如果还没有开始填写，我们并不能随意更改前两位的数字记录，因此我们需要知道在前面是否已经开始填写大于0的数字，如果开始了，就需要更新前两位数字，否则不能更改
        sNum = str(num2)
        @cache
        def dfs(indx, last2, last1, isSmall, started, cnt):
            if indx == len(sNum):
                return cnt
            begin = 0
            end = int(sNum[indx])
            if isSmall:
                end = 9
            ans = 0
            for cur in range(begin, end+1):
                curStarted = started or cur>0
                curSmall = isSmall or cur<int(sNum[indx])
                if not curStarted:
                    ans += dfs(indx+1, last2, last1, curSmall, curStarted, 0)
                else:
                    if last2 == -float("inf") or last1 == -float("inf"):
                        ans += dfs(indx+1, last1, cur, curSmall, curStarted, 0)
                        continue
                    if (last1 > last2 and last1 > cur) or (last1 < last2 and last1 < cur):
                        ans += dfs(indx+1, last1, cur, curSmall, curStarted, cnt+1)
                    else:
                        ans += dfs(indx+1, last1, cur, curSmall, curStarted, cnt)
            return ans
            
        res = dfs(0, -float("inf"), -float("inf"), False, False, 0)
        dfs.cache_clear()
        sNum = str(num1-1)
        res -= dfs(0, -float("inf"), -float("inf"), False, False, 0)
        return res

if __name__ == "__main__":
    s = Solution()
    num1, num2 = 120, 130
    print(s.totalWaviness(num1, num2))
