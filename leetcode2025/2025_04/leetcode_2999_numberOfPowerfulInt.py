from typing import *

class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        # 用前缀和的思路，因为我们要求的是区间[start,finish]内的强大整数数目，所以可以考虑先分别求出[0,finish]和[0,start)内的强大整数数目，然后将两者相减即可
        # 定义函数calc(curStr)用来计算[0,int(curStr)]内的强大整数数目，因此答案就是calc(str(finish))-calc(str(start-1))
        # 首先考虑以下两个基础情况。
        # 1.len(curStr)<len(s) 此时int(curStr)一定小于int(s)，所以在[0,int(curStr)]没有以s结尾的整数，返回0；
        # 2.len(curStr)==len(s) 此时又有两种情况，如果int(curStr)>=int(s)，那么在[0,int(curStr)]中就有一个以s结尾的整数即s本身，返回1，否则返回0，为了方便返回int(curStr)>=int(s)即可
        # 之后，我们便可以保证int(curStr)>int(s)并且curStr的位数大于s的位数，那么接下来我们将curStr分成两部分，一部分是curStr末尾和s长度相同的后缀suffix，另一部分则是前面剩余的部分prefix。分析一下题目，为了找到[0,int(curStr)]中的强大整数数目，相当于在后缀s的前面加上一个数字n，同时保证n<=int(prefix)，且n的任何一位都小于等于limit，求n的所有可能数目
        # 那么我们采用填数字的思路，从prefix的第0位开始填。当我们填第i位时，假定n的前i位已经确定并且和prefix的前i位相同，因为要保证n的每一位都小于等于limit，因此接下来分两种情况考虑。
        # 1.如果int(prefix[i])>limit，那么说明当前这一位的取值范围最大就是[0,limit]，但由于n在第i位的值已经小于prefix第i位的值了，所以后面所有位的取值范围都能够达到[0,limit]，所以当前位及其之后的所有位置的情况总数就是(limit+1)**(len(prefix)-i)，此时直接加上之前累计的情况返回答案即可
        # 2.如果int(prefix[i])<=limit，那么我们暂时不考虑n的第i位和prefix的第i位相同的情况，因为我们无法保证当int(n[i])==int(prefix[i])时后面数字的取值范围是否能够确定。所以第i位的取值范围只考虑[0,int(prefix[i])-1]，那么第i位就只有prefix[i]种情况，但是之后的所有位置的取值范围都可以达到[0,limit]，因此当前位及其之后的所有位置的情况总数就是prefix[i]*((limit+1)**(len(prefix)-i-1))。我们不需要担心不考虑int(n[i])=int(prefix[i])的情况是否会漏算，因为当我们循环到i+1时，int(n[i])已经默认置为int(prefix[i])了
        # 如果到循环结束还没有返回值，那么就需要考虑suffix和s的大小情况，如果int(suffix)>int(s)，那么我们就多一个答案，即int(prefix+s)，否则由于int(prefix+s)会超过int(curStr)，不能加最后这个情况
        # 最后将所有情况判断完，将累计的答案返回即可
        def calc(curStr):
            if len(curStr) < len(s):
                return 0
            if len(curStr) == len(s):
                return int(curStr)>=int(s)
            
            mx = len(curStr)-len(s)
            suffix = curStr[mx:]
            ans = 0

            for i in range(mx):
                if int(curStr[i]) > limit:
                    ans += (limit+1)**(mx-i)
                    return ans
                ans += int(curStr[i])*(limit+1)**(mx-i-1)
            
            if int(suffix) >= int(s):
                ans += 1
            return ans

        StrStart = str(start-1)
        StrFinish = str(finish)
        return calc(StrFinish)-calc(StrStart)

if __name__ == "__main__":
    sl = Solution()
    start = 1
    finish = 6000
    limit = 4
    s = "124"
    print(sl.numberOfPowerfulInt(start, finish, limit, s))
